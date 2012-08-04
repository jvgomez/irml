#include <fstream>
#include <iostream>
#include <string>
#include "yaml-cpp/yaml.h"

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

#include "rawDepth.h"

using namespace std;
 
int main()
{
	std::ifstream fin("img_0848.yml");
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
			cloud.points[i].x = (col - 339.30546187516956) * depth[i] / 594.21480358642339;   // http://nicolas.burrus.name/index.php/Research/KinectCalibration
			cloud.points[i].y = (row - 242.73843891390746) * depth[i] / 591.04092248505947;
			cloud.points[i].z = depth[i];
		}
	}
	
	pcl::io::savePCDFileASCII ("test_pcd.pcd", cloud);

	return 0;
}
 
