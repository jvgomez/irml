#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include <string>
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/console/time.h>
#include <pcl/filters/passthrough.h>
#include <pcl/features/normal_3d.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/common/common.h>
#include <Eigen/Core>
#include <pcl/point_cloud.h>
#include <pcl/console/time.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/fpfh.h>
#include <pcl/registration/ia_ransac.h>
 
 using namespace std;
 
 
 class FeatureCloud
{
  public:
    // A bit of shorthand
    typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
    typedef pcl::PointCloud<pcl::Normal> SurfaceNormals;
    typedef pcl::PointCloud<pcl::FPFHSignature33> LocalFeatures;
    typedef pcl::search::KdTree<pcl::PointXYZ> SearchMethod;

    FeatureCloud () :
      search_method_xyz_ (new SearchMethod),
      normal_radius_ (0.15f),
      feature_radius_ (0.15f)
    {}

    ~FeatureCloud () {}

    // Process the given cloud
    void
    setInputCloud (PointCloud::Ptr xyz)
    {
      xyz_ = xyz;
      processInput ();
    }
    
    void
    setCloudName (std::string &name) 
    {
		name_ = name;
	}

    // Load and process the cloud in the given PCD file
    void
    loadInputCloud (const std::string &pcd_file)
    {
      xyz_ = PointCloud::Ptr (new PointCloud);
      pcl::io::loadPCDFile (pcd_file, *xyz_);
      name_ = pcd_file;
      processInput ();
    }

    // Get a pointer to the cloud 3D points
    PointCloud::Ptr
    getPointCloud () const
    {
      return (xyz_);
    }
    
    std::string
    getCloudName () const
    {
		return (name_);
	}

    // Get a pointer to the cloud of 3D surface normals
    SurfaceNormals::Ptr
    getSurfaceNormals () const
    {
      return (normals_);
    }

    // Get a pointer to the cloud of feature descriptors
    LocalFeatures::Ptr
    getLocalFeatures () const
    {
      return (features_);
    }

  protected:
    // Compute the surface normals and local features
    void
    processInput ()
    {
      computeSurfaceNormals ();
      computeLocalFeatures ();
    }

    // Compute the surface normals
    void
    computeSurfaceNormals ()
    {
      normals_ = SurfaceNormals::Ptr (new SurfaceNormals);

      pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> norm_est;
      norm_est.setInputCloud (xyz_);
      norm_est.setSearchMethod (search_method_xyz_);
      norm_est.setRadiusSearch (normal_radius_);
      norm_est.compute (*normals_);
    }

    // Compute the local feature descriptors
    void
    computeLocalFeatures ()
    {
      features_ = LocalFeatures::Ptr (new LocalFeatures);

      pcl::FPFHEstimation<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_est;
      fpfh_est.setInputCloud (xyz_);
      fpfh_est.setInputNormals (normals_);
      fpfh_est.setSearchMethod (search_method_xyz_);
      fpfh_est.setRadiusSearch (feature_radius_);
      fpfh_est.compute (*features_);
    }

  private:
    // Point cloud data
    PointCloud::Ptr xyz_;
    SurfaceNormals::Ptr normals_;
    LocalFeatures::Ptr features_;
    SearchMethod::Ptr search_method_xyz_;
    std::string name_;

    // Parameters
    float normal_radius_;
    float feature_radius_;
};

class TemplateAlignment
{
  public:

    // A struct for storing alignment results
    struct Result
    {
      float fitness_score;
      Eigen::Matrix4f final_transformation;
      EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    };

    TemplateAlignment () :
      min_sample_distance_ (0.1f),
      max_correspondence_distance_ (0.01f*0.01f),
      nr_iterations_ (500)
    {
      // Intialize the parameters in the Sample Consensus Intial Alignment (SAC-IA) algorithm
      sac_ia_.setMinSampleDistance (min_sample_distance_);
      sac_ia_.setMaxCorrespondenceDistance (max_correspondence_distance_);
      sac_ia_.setMaximumIterations (nr_iterations_);
    }

    ~TemplateAlignment () {}

    // Set the given cloud as the target to which the templates will be aligned
    void
    setTargetCloud (FeatureCloud &target_cloud)
    {
      target_ = target_cloud;
      sac_ia_.setInputTarget (target_cloud.getPointCloud ());
      sac_ia_.setTargetFeatures (target_cloud.getLocalFeatures ());
    }

    // Add the given cloud to the list of template clouds
    void
    addTemplateCloud (FeatureCloud &template_cloud)
    {
      templates_.push_back (template_cloud);
    }

    // Align the given template cloud to the target specified by setTargetCloud ()
    void
    align (FeatureCloud &template_cloud, TemplateAlignment::Result &result)
    {
      sac_ia_.setInputCloud (template_cloud.getPointCloud ());
      sac_ia_.setSourceFeatures (template_cloud.getLocalFeatures ());

      pcl::PointCloud<pcl::PointXYZ> registration_output;
      sac_ia_.align (registration_output);

      result.fitness_score = (float) sac_ia_.getFitnessScore (max_correspondence_distance_);
      std::cout << template_cloud.getCloudName() << " has a score of: " << result.fitness_score << std::endl;
      result.final_transformation = sac_ia_.getFinalTransformation ();
    }

    // Align all of template clouds set by addTemplateCloud to the target specified by setTargetCloud ()
    void
    alignAll (std::vector<TemplateAlignment::Result, Eigen::aligned_allocator<Result> > &results)
    {
      results.resize (templates_.size ());
      for (size_t i = 0; i < templates_.size (); ++i)
      {
		own_timer.tic();
        align (templates_[i], results[i]);
        cout << "One alingment: ";
		own_timer.toc_print();
      }
    }

    // Align all of template clouds to the target cloud to find the one with best alignment score
    int
    findBestAlignment (TemplateAlignment::Result &result)
    {
      // Align all of the templates to the target cloud
      std::vector<Result, Eigen::aligned_allocator<Result> > results;
      alignAll (results);

      // Find the template with the best (lowest) fitness score
      float lowest_score = std::numeric_limits<float>::infinity ();
      int best_template = 0;
      for (size_t i = 0; i < results.size (); ++i)
      {
        const Result &r = results[i];
        if (r.fitness_score < lowest_score)
        {
          lowest_score = r.fitness_score;
          best_template = (int) i;
        }
      }

      // Output the best alignment
      result = results[best_template];
      return (best_template);
    }

  private:
    // A list of template clouds and the target to which they will be aligned
    std::vector<FeatureCloud> templates_;
    FeatureCloud target_;

    // The Sample Consensus Initial Alignment (SAC-IA) registration routine and its parameters
    pcl::SampleConsensusInitialAlignment<pcl::PointXYZ, pcl::PointXYZ, pcl::FPFHSignature33> sac_ia_;
    float min_sample_distance_;
    float max_correspondence_distance_;
    int nr_iterations_;
    pcl::console::TicToc own_timer;
};

/***********************************************************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
 
 int main (int argc, char** argv) {
	 
	if (argc > 1) 
		cout << "\33[4;34m" << "Reading:" << "\33[0m" << " " << argv[2] << endl;
	else {
		cerr << "\33[31m" << "You must provide the root path of the pcd files." << "\33[0m" << endl;
		return 0;
	}

		pcl::console::TicToc timer;

		pcl::PointCloud<pcl::PointXYZ>::Ptr init_cloud (new pcl::PointCloud<pcl::PointXYZ>);
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
		
		// Fill in the cloud data
  		pcl::PCDReader reader;
		reader.read (argv[2], *init_cloud);
		cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;
		
			
		 /*****************************************
		 * Passthrough filter
		 * ***************************************/
		pcl::PassThrough<pcl::PointXYZ> pass;
		cout << "\33[4;34m" << "Removing background data:" << "\33[0m" << endl;   
		timer.tic();
		
		pass.setInputCloud (init_cloud);
		pass.setFilterFieldName ("z");
		pass.setFilterLimits (0.0, 4.5);
		//pass.setFilterLimitsNegative (true);
		pass.filter (*cloud);
		
		cout << "Time elapsed: ";
		timer.toc_print();
		cerr << "\33[4;33m" << "Cloud after downsampling:" << "\33[0m" << endl;
		cerr << *cloud << endl;
		cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;
		
		 /*****************************************
		 * Downsampling.
		 * ***************************************/
		float leaf_size = 0.01;
		pcl::VoxelGrid<pcl::PointXYZ> sor;
		pcl::PointCloud<pcl::PointXYZ>::Ptr downs_cloud (new pcl::PointCloud<pcl::PointXYZ>);
		cout << "\33[4;34m" << "Downsampling:" << "\33[0m" << endl;   
		timer.tic();
		
		sor.setInputCloud (cloud);
		sor.setLeafSize (leaf_size, leaf_size, leaf_size);
		sor.filter (*downs_cloud);
		
		cout << "Time elapsed: ";
		timer.toc_print();
		cerr << "\33[4;33m" << "Cloud after downsampling:" << "\33[0m" << endl;
		cerr << *downs_cloud << endl;
		cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;
		
		 /*****************************************
		 * Planar segmentation.
		 * ***************************************/
		pcl::SACSegmentation<pcl::PointXYZ> seg;  
		cout << "\33[4;34m" << "Main planes removal:" << "\33[0m" << endl; 
		timer.tic();

		seg.setOptimizeCoefficients (true);
		seg.setModelType (pcl::SACMODEL_PLANE);
		seg.setMethodType (pcl::SAC_RANSAC);
		seg.setMaxIterations (500);
		seg.setDistanceThreshold (0.05);
		
		// Segment the largest planar component from the remaining cloud
		pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients ());
		pcl::PointIndices::Ptr inliers (new pcl::PointIndices ());
		
		seg.setInputCloud (downs_cloud);
		seg.segment (*inliers, *coefficients);
		
		if (inliers->indices.size () == 0)
		  cerr << "\33[31m" << "Could not estimate a planar model for the given dataset." << "\33[0m" << endl;

		// Removing the segmented part from the initial cloud.
		pcl::PointCloud<pcl::PointXYZ>::Ptr woplanes_cloud (new pcl::PointCloud<pcl::PointXYZ>);
		pcl::ExtractIndices<pcl::PointXYZ> extract;
		pcl::PCDWriter writer;
			
		extract.setInputCloud (downs_cloud);
		extract.setIndices (inliers);
		extract.setNegative (true);
		extract.filter (*woplanes_cloud);
		
		cout << "Time elapsed: ";
		timer.toc_print();
		cerr << "\33[4;33m" << "Cloud after main planes removal:" << "\33[0m" << endl;
		cerr << *woplanes_cloud << endl;
		cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;
		
		
		/*****************************************
		 * Euclidean clustering
		 * ***************************************/
		pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
		std::vector<pcl::PointIndices> cluster_indices;
		pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
		cout << "\33[4;34m" << "Euclidean clustering:" << "\33[0m" << endl; 
		timer.tic();
		
		tree->setInputCloud (woplanes_cloud);
		ec.setClusterTolerance (0.1); 
		ec.setMinClusterSize (800);
		ec.setMaxClusterSize (8000);
		ec.setSearchMethod (tree);
		ec.setInputCloud (woplanes_cloud);
		ec.extract (cluster_indices);

		int j = 0;
		for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end (); ++it) 	{
			pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZ>);
			
			for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); pit++)
				cloud_cluster->points.push_back (woplanes_cloud->points[*pit]); //*
				
			cloud_cluster->width = cloud_cluster->points.size ();
			cloud_cluster->height = 1;
			cloud_cluster->is_dense = true;

			std::cout << "PointCloud representing the Cluster: " << cloud_cluster->points.size () << " data points." << std::endl;
			std::stringstream ss;
			ss << "Clusters/" << "cluster" << j << ".pcd";
			writer.write<pcl::PointXYZ> (ss.str (), *cloud_cluster, false); //*
			j++;
		}
	 
		cout << "Time elapsed: ";
		timer.toc_print();
		cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;
		
				
		/*****************************************
		 * Loading and processing templates
		 * ***************************************/
		
		cout << "\33[4;34m" << "Loading and processing templates:" << "\33[0m" << endl; 
		timer.tic();
		std::vector<FeatureCloud> object_templates;
	  std::ifstream input_stream (argv[1]);
	  object_templates.resize (0);
	  std::string pcd_filename;
	  while (input_stream.good ()) // Loading all the templates
	{
		timer.tic();
		 std::getline (input_stream, pcd_filename);
		if (pcd_filename.empty () || pcd_filename.at (0) == '#') // Skip blank lines or comments
		  continue;

		FeatureCloud template_cloud;
		template_cloud.loadInputCloud (pcd_filename);
		object_templates.push_back (template_cloud);
		cout << "Time elapsed: ";
		timer.toc_print();
	}
	
	input_stream.close ();	
	cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;
	
		
	/*****************************************
	 * Template alignment with the clusters found.
	 * ***************************************/
	 cout << "\33[4;34m" << "Template alignment:" << "\33[0m" << endl; 
	for (int k = 0; k < j; k++) // All the clusters
	{
		timer.tic();
		pcl::PointCloud<pcl::PointXYZ>::Ptr cluster (new pcl::PointCloud<pcl::PointXYZ>);
		std::stringstream ss;
		ss << "Clusters/" << "cluster" << k << ".pcd";
		pcl::PCDReader reader;
		reader.read (ss.str(), *cluster);
		
		 FeatureCloud target_cloud;
		target_cloud.setInputCloud (cluster);
		
		// Set the TemplateAlignment inputs
		  TemplateAlignment template_align;
		  for (size_t i = 0; i < object_templates.size (); ++i)
		  {
			template_align.addTemplateCloud (object_templates[i]);
		  }
		  template_align.setTargetCloud (target_cloud);

		  // Find the best template alignment
		  TemplateAlignment::Result best_alignment;
		  int best_index = template_align.findBestAlignment (best_alignment);
		  const FeatureCloud &best_template = object_templates[best_index];

		  // Print the alignment fitness score (values less than 0.00002 are good)
		  printf ("Best fitness score: %f\n", best_alignment.fitness_score);
		  std::cout << "The best template is: "<< best_template.getCloudName() << std::endl;

		  // Print the rotation matrix and translation vector
		  Eigen::Matrix3f rotation = best_alignment.final_transformation.block<3,3>(0, 0);
		  Eigen::Vector3f translation = best_alignment.final_transformation.block<3,1>(0, 3);

		  printf ("\n");
		  printf ("    | %6.3f %6.3f %6.3f | \n", rotation (0,0), rotation (0,1), rotation (0,2));
		  printf ("R = | %6.3f %6.3f %6.3f | \n", rotation (1,0), rotation (1,1), rotation (1,2));
		  printf ("    | %6.3f %6.3f %6.3f | \n", rotation (2,0), rotation (2,1), rotation (2,2));
		  printf ("\n");
		  printf ("t = < %0.3f, %0.3f, %0.3f >\n", translation (0), translation (1), translation (2));

		  // Save the aligned template for visualization
		  pcl::PointCloud<pcl::PointXYZ> transformed_cloud;
		  pcl::transformPointCloud (*best_template.getPointCloud (), transformed_cloud, best_alignment.final_transformation);
		  std::stringstream ss2;
		  ss2 << "Output" << k << ".pcd";
		  pcl::io::savePCDFileBinary (ss2.str(), transformed_cloud);
		  cout << "Time elapsed: ";
			timer.toc_print();
	}	
		
}
