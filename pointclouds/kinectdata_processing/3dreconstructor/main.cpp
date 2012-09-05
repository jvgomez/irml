#include <fstream>
#include <iostream>
#include <string>
#include "yaml-cpp/yaml.h"

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

#include "rawDepth.h"

using namespace std;
 
int main(int argc, char* argv[])
{
	char * filename;
	if (argc > 1)  filename = argv[1];
	else
	{
		cerr<<"You must specify a filename with a point cloud in format: x\ty\tz"<<endl;
		return 0;
	}
	std::ifstream fin(filename);
	YAML::Parser parser(fin);
	YAML::Node doc;
	parser.GetNextDocument(doc);

	DepthRaw m;
	doc["depth"] >> m;
	
	cout << m;
	
	vector<float> depth;
	depth = m.getDepthData();
	
	//TODO: getWidth() and getHeight()
	unsigned int width = m.width_;
	unsigned int height = m.height_;
	//float minDistance = -10;				// http://openkinect.org/wiki/Imaging_Information
	//float scaleFactor = 0.0021;
		
		
	pcl::PointCloud<pcl::PointXYZ> cloud;
	cloud.width    = width * height;
	cloud.height   = 1;
	//cloud.is_dense = false;
	cloud.points.resize (cloud.width * cloud.height);
	
	//for(std::vector<float>::iterator it = depth.begin(); it != depth.end(); ++it) {
	for (int row = 0; row < 480 ; ++row) {
		for (int col = 0; col < 640 ; ++col) {
			unsigned int i = row*640 + col;
			cloud.points[i].x = (col - 339.30780975300314) * depth[i] / 594.21434211923247;   // http://nicolas.burrus.name/index.php/Research/KinectCalibration
			cloud.points[i].y = (row - 242.73913761751615) * depth[i] / 591.04053696870778;
			cloud.points[i].z = depth[i];
		}
	}
	
	strcat(filename, ".pcd");
	
	pcl::io::savePCDFileASCII (filename, cloud);

	return 0;
}
 
