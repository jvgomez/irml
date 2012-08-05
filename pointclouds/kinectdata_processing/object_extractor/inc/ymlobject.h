/*******************************************************
* Class to store the data of an object in a 
* kinectdata.com database scene.
********************************************************/

#ifndef YMLOBJECT_H_
#define YMLOBJECT_H_

#include <string>
#include <vector>
#include <pcl/point_types.h>

#include "yaml-cpp/yaml.h"

class YmlObject{
	friend std::ostream& operator << (std::ostream& , YmlObject&);
	friend void operator >> (const YAML::Node& node,YmlObject& y);
	
public:
	YmlObject() 	{ }
	YmlObject(std::string p): path_(p) {read();}
	~YmlObject() 	{ }
	
	void read ();
	void getPointCloud(pcl::PointCloud<pcl::PointXYZ>& cloud, int xmin, int xmax, int ymin, int ymax);
	
//TODO: private:
	int width_;
	int height_;
	std::string path_;
	std::vector<float> rawData_;
	
};

#endif
