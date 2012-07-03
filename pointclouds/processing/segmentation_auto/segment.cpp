#include <iostream>
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
#include <cmath>

#include "diranalyzer.h"
#include "file.h"
 
 using namespace std;
 
 int main (int argc, char** argv) {
	 
	if (argc > 1) 
		cout << "\33[4;34m" << "Reading:" << "\33[0m" << " " << argv[1] << endl;
	else {
		cerr << "\33[31m" << "You must provide the root path of the pcd files." << "\33[0m" << endl;
		return 0;
	}
	 
	 DirAnalyzer	dirAnalyzer;
	 vector<File> cloud_files;
	 
	 dirAnalyzer.getFiles(argv[1], cloud_files);
	 
	 for (vector<File>::iterator it (cloud_files.begin()); it!=cloud_files.end(); ++it) {
		 
		string name = it -> getPath();
		char * name_cstr = new char [name.size()+1];
		strcpy (name_cstr, name.c_str());

		string name2 = it -> getName();
		name2.erase(name2.end()-4, name2.end());
		char * name_cstr2 = new char [name2.size()+1];
		strcpy (name_cstr2, name2.c_str());
	 
	 
		pcl::console::TicToc timer;

		pcl::PointCloud<pcl::PointXYZ>::Ptr init_cloud (new pcl::PointCloud<pcl::PointXYZ>);
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
		
		// Fill in the cloud data
		pcl::PCDReader reader;
		reader.read (name_cstr, *init_cloud);
		cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;
		
			
		 /*****************************************
		 * Passthrough filter
		 * ***************************************/
		pcl::PassThrough<pcl::PointXYZ> pass;
		cout << "\33[4;34m" << "Removing background data:" << "\33[0m" << endl;   
		timer.tic();
		
		pass.setInputCloud (init_cloud);
		pass.setFilterFieldName ("z");
		pass.setFilterLimits (0.0, 3.5);
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
		ec.setClusterTolerance (0.3); // 2cm
		ec.setMinClusterSize (800);
		ec.setMaxClusterSize (10000);
		ec.setSearchMethod (tree);
		ec.setInputCloud (woplanes_cloud);
		ec.extract (cluster_indices);
		
		float min_z = 9999.9;
		float min_x = 9999.9;
		pcl::PointCloud<pcl::PointXYZ> clust;
		
		for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end (); ++it) 	{
			pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZ>);
			
			for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); pit++)
				cloud_cluster->points.push_back (woplanes_cloud->points[*pit]); //*
				
			cloud_cluster->width = cloud_cluster->points.size ();
			cloud_cluster->height = 1;
			cloud_cluster->is_dense = true;
			
			std::cout << "PointCloud representing the Cluster: " << cloud_cluster->points.size () << " data points." << std::endl;
			 
			Eigen::Vector4f centroid; 
			pcl::compute3DCentroid(*cloud_cluster, centroid);
			
			//if (fabs(centroid[0]) < min_x){ 
				if (centroid[2] < min_z) {
					min_z = centroid[2] ;
					//min_x = centroid[0];
					clust = *cloud_cluster;
				}
			//}
		}	
		std::stringstream ss;
		ss << "Clusters/" << name_cstr2 << "_maincluster" << ".pcd";
		writer.write<pcl::PointXYZ> (ss.str (), clust, false); //*
	 
		cout << "Time elapsed: ";
		timer.toc_print();
		cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;
		
		/*****************************************
		 * Obtaining the main object
		 * ***************************************/
		/*cout << "\33[4;34m" << "Main object extraction:" << "\33[0m" << endl; 
		timer.tic();
		
		for (int i = 0; i < cluster_indices.size (); i++) {
				Eigen::Vector4f centroid;
				pcl::compute3DCentroid (processed_cloud2, cluster_indices, centroid);
				cout << centroid[0] << " " <<  centroid[1] << " " <<   centroid[2] << " " <<   centroid[3] << " \n";
			}
		
		
		cout << "Time elapsed: ";
		timer.toc_print();
		cout << "\33[1;32m" << "DONE!" << "\33[0m" << endl << endl;*/
		
		//writer.write<pcl::PointXYZ> ("test.pcd", *woplanes_cloud, false);
		// Create the filtering object
		//extract.setNegative (true);
		//extract.filter (*cloud_to_segment);

	}

}
