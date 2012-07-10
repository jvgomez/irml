#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/console/time.h>

#include <pcl/features/normal_3d.h>
#include <pcl/features/vfh.h>
#include "diranalyzer.h"
#include "file.h"

using namespace std;

typedef pcl::search::KdTree<pcl::PointXYZ> SearchMethod;

int
main (int argc, char **argv)
{
	pcl::console::TicToc total_timer;
	pcl::console::TicToc timer;
	
	total_timer.tic();
	
	DirAnalyzer	dirAnalyzer;
	vector<File> clouds;
	dirAnalyzer.getFiles(argv[1], clouds);

	
	for (vector<File>::iterator it (clouds.begin()); it != clouds.end(); ++it) {
		timer.tic();
		
		string name = it -> getPath();
		cout << "Computing VFH for: " << name << endl;
	
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
		pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal> ());
		SearchMethod::Ptr searchxyz;
		
		pcl::io::loadPCDFile (name, *cloud);
		
		pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> norm_est;
		norm_est.setInputCloud (cloud);
		norm_est.setSearchMethod (searchxyz);
		norm_est.setRadiusSearch (0.15f);
		norm_est.compute (*normals);
		
		
		pcl::VFHEstimation<pcl::PointXYZ, pcl::Normal, pcl::VFHSignature308> vfh;
		vfh.setInputCloud (cloud);
		vfh.setInputNormals (normals);
		
		//pcl::KdTreeFLANN<pcl::PointXYZ>::Ptr tree (new pcl::KdTreeFLANN<pcl::PointXYZ> ());
		vfh.setSearchMethod (pcl::search::KdTree<pcl::PointXYZ>::Ptr (new pcl::search::KdTree<pcl::PointXYZ>));

		// Output datasets
		pcl::PointCloud<pcl::VFHSignature308>::Ptr vfhs (new pcl::PointCloud<pcl::VFHSignature308> ());

		// Compute the features
		vfh.compute (*vfhs);
		
		stringstream ss;
		name.erase(name.end()-4, name.end()); //Extension removal.
		name.erase(name.begin(), name.end()-8); //Path removal.
		ss << "VFH/" << name << "_feat.pcd";
		pcl::io::savePCDFile (ss.str(), *vfhs);
		
		cout << "Time elapsed: ";
		timer.toc_print();
	} // For features_files
	
}
