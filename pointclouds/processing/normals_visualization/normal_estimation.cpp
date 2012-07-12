#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/cloud_viewer.h>

using namespace std;

 int
 main (int argc, char** argv)
 {
	//HOW TO USE THIS PROGRAM:
	// ./normal_estimation input.pcd <Kneighbours> <normal_length>
	// Example
	// ./normal_estimation c001_001.pcd 8 0.05
	 
	// load point cloud
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile (argv[1], *cloud);

	pcl::search::KdTree<pcl::PointXYZ>::Ptr searchxyz;

	// estimate normals
	pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
	ne.setInputCloud(cloud);
	ne.setSearchMethod (searchxyz);
	ne.setKSearch(atoi(argv[2]));
	ne.compute(*normals);
	
	pcl::PCDWriter	writer;
	
	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>); 
	pcl::concatenateFields(*cloud, *normals, *cloud_with_normals); 
	
	writer.write("normals.pcd", *cloud_with_normals);

	// visualize normals
	pcl::visualization::PCLVisualizer viewer("PCL Viewer");
	viewer.setBackgroundColor (0.0, 0.0, 0.0);
	viewer.addPointCloudNormals<pcl::PointXYZ,pcl::Normal>(cloud, normals, 1, atoi(argv[3]));

	while (!viewer.wasStopped ())
	{
	viewer.spinOnce ();
	}
	return 0;
 }
