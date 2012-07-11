#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/common/common.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>
#include <pcl/console/print.h>
#include <pcl/io/pcd_io.h>
#include <iostream>
#include <flann/flann.h>
#include <flann/io/hdf5.h>
#include <boost/filesystem.hpp>

#include "diranalyzer.h"
#include "file.h"

typedef std::pair<std::string, std::vector<float> > vfh_model;

/** \brief Loads an n-D histogram file as a VFH signature
  * \param path the input file name
  * \param vfh the resultant VFH model
  */
bool
loadHist (const boost::filesystem::path &path, vfh_model &vfh)
{
  int vfh_idx;
  // Load the file as a PCD
  try
  {
    sensor_msgs::PointCloud2 cloud;
    int version;
    Eigen::Vector4f origin;
    Eigen::Quaternionf orientation;
    pcl::PCDReader r;
    int type; 
    int idx;
    r.readHeader (path.string (), cloud, origin, orientation, version, type, idx);

    vfh_idx = pcl::getFieldIndex (cloud, "vfh");
    if (vfh_idx == -1)
      return (false);
    if ((int)cloud.width * cloud.height != 1)
      return (false);
  }
  catch (pcl::InvalidConversionException e)
  {
    return (false);
  }

  // Treat the VFH signature as a single Point Cloud
  pcl::PointCloud <pcl::VFHSignature308> point;
  pcl::io::loadPCDFile (path.string (), point);
  vfh.second.resize (308);

  std::vector <sensor_msgs::PointField> fields;
  getFieldIndex (point, "vfh", fields);

  for (size_t i = 0; i < fields[vfh_idx].count; ++i)
  {
    vfh.second[i] = point.points[0].histogram[i];
  }
  vfh.first = path.string ();
  return (true);
}


/** \brief Search for the closest k neighbors
  * \param index the tree
  * \param model the query model
  * \param k the number of neighbors to search for
  * \param indices the resultant neighbor indices
  * \param distances the resultant neighbor distances
  */
inline void
nearestKSearch (flann::Index<flann::ChiSquareDistance<float> > &index, const vfh_model &model, 
                int k, flann::Matrix<int> &indices, flann::Matrix<float> &distances)
{
  // Query point
  flann::Matrix<float> p = flann::Matrix<float>(new float[model.second.size ()], 1, model.second.size ());
  memcpy (&p.ptr ()[0], &model.second[0], p.cols * p.rows * sizeof (float));

  indices = flann::Matrix<int>(new int[k], 1, k);
  distances = flann::Matrix<float>(new float[k], 1, k);
  index.knnSearch (p, indices, distances, k, flann::SearchParams (512));
  delete[] p.ptr ();
}

/** \brief Load the list of file model names from an ASCII file
  * \param models the resultant list of model name
  * \param filename the input file name
  */
bool
loadFileList (std::vector<vfh_model> &models, const std::string &filename)
{
  ifstream fs;
  fs.open (filename.c_str ());
  if (!fs.is_open () || fs.fail ())
    return (false);

  std::string line;
  while (!fs.eof ())
  {
    getline (fs, line);
    if (line.empty ())
      continue;
    vfh_model m;
    m.first = line;
    models.push_back (m);
  }
  fs.close ();
  return (true);
}

int
main (int argc, char** argv)
{
  double thresh = DBL_MAX;     // No threshold, disabled by default

 
   DirAnalyzer	dirAnalyzer;
	vector<File> files;
	dirAnalyzer.getFiles(argv[1], files);
	
	//int k = files.size();
	int k = 1;

	for (vector<File>::iterator it (files.begin()); it!=files.end(); ++it) {
	  vfh_model histogram;
	  
	  string name = it -> getPath();
		loadHist(name,histogram);
	  
	  pcl::console::print_highlight ("Using "); pcl::console::print_value ("%d", k); pcl::console::print_info (" nearest neighbors.\n");

	  std::string kdtree_idx_file_name = "kdtree.idx";
	  std::string training_data_h5_file_name = "training_data.h5";
	  std::string training_data_list_file_name = "training_data.list";

	  std::vector<vfh_model> models;
	  flann::Matrix<int> k_indices;
	  flann::Matrix<float> k_distances;
	  flann::Matrix<float> data;
	  // Check if the data has already been saved to disk
	  if (!boost::filesystem::exists ("training_data.h5") || !boost::filesystem::exists ("training_data.list"))
	  {
		pcl::console::print_error ("Could not find training data models files %s and %s!\n", 
			training_data_h5_file_name.c_str (), training_data_list_file_name.c_str ());
		return (-1);
	  }
	  else
	  {
		loadFileList (models, training_data_list_file_name);
		flann::load_from_file (data, training_data_h5_file_name, "training_data");
		pcl::console::print_highlight ("Training data found. Loaded %d VFH models from %s/%s.\n", 
			(int)data.rows, training_data_h5_file_name.c_str (), training_data_list_file_name.c_str ());
	  }

	  // Check if the tree index has already been saved to disk
	  if (!boost::filesystem::exists (kdtree_idx_file_name))
	  {
		pcl::console::print_error ("Could not find kd-tree index in file %s!", kdtree_idx_file_name.c_str ());
		return (-1);
	  }
	  else
	  {
		flann::Index<flann::ChiSquareDistance<float> > index (data, flann::SavedIndexParams ("kdtree.idx"));
		index.buildIndex ();
		nearestKSearch (index, histogram, k, k_indices, k_distances);
	  }

	fstream outputFile("distances.csv", fstream::out | fstream::app);
	for (int i = 0; i < k; ++i)
		outputFile << name << "\t" << models.at (k_indices[0][i]).first.c_str () << "\t" << k_distances[0][i] << endl;
	outputFile.close();	
	}
  return (0);
}
