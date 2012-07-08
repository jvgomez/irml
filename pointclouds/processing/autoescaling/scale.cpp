#include <iostream>
#include <sstream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/console/time.h>

using namespace std;
 
int main (int argc, char** argv) {

	  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
	  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2 (new pcl::PointCloud<pcl::PointXYZ>);
	  pcl::PointCloud<pcl::PointXYZ> cloud2_r;
	  pcl::PCDWriter writer;

	if (pcl::io::loadPCDFile<pcl::PointXYZ> (argv[1], *cloud) == -1) { //* load the file
		PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
		return (-1);
	}
	
	if (pcl::io::loadPCDFile<pcl::PointXYZ> (argv[2], *cloud2) == -1) { //* load the file
		PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
		return (-1);
	}
	
	pcl::console::TicToc timer;
	timer.tic();
	
	float max_z = -9999999;
	float min_z =  9999999;
	for (size_t i = 0; i < cloud->points.size (); ++i) {
		if (cloud->points[i].z > max_z) max_z = cloud->points[i].z;
		if (cloud->points[i].z < min_z) min_z = cloud->points[i].z;
	}
	
	float height = max_z - min_z;
	cout << "Height: " << height << endl;

	float max_z2 = -9999999;
	float min_z2 =  9999999;
	for (size_t i = 0; i < cloud2->points.size (); ++i) {
		if (cloud2->points[i].z > max_z2) max_z2 = cloud2->points[i].z;
		if (cloud2->points[i].z < min_z2) min_z2 = cloud2->points[i].z;
	}
	
	float height2 = max_z2 - min_z2;
	cout << "Height2: " << height2 << endl;
	
	float scale = height / height2;
	cout << "Scale: " << scale  << endl;
	
	// The cloud 2 will be adapted to be the same height as the cloud 1.	
	cloud2_r.width    = cloud2->width;
	cloud2_r.height   = cloud2->height;
	cloud2_r.points.resize (cloud2->width * cloud2->height);

	for (size_t i = 0; i < cloud2->points.size (); ++i) {
		
		cloud2_r.points[i].x = cloud2->points[i].x * scale;
		cloud2_r.points[i].y = cloud2->points[i].y * scale;
		cloud2_r.points[i].z = cloud2->points[i].z * scale;
	}
	
	timer.toc_print();
	
	string name(argv[2]);
	name.erase(name.end()-4, name.end());
	char * name_cstr = new char [name.size()+1];
	strcpy (name_cstr, name.c_str());
	
	stringstream ss;
	ss << name_cstr << "_scaled.pcd";
	writer.write<pcl::PointXYZ> (ss.str (), cloud2_r); //*
}
