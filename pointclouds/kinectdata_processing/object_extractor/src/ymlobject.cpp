#include "ymlobject.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ostream& operator << (ostream& stream, YmlObject& ob) {
	stream << "\33[4;33m"<< "YAML File:" << "\33[0m" << " " <<ob.path_ << endl;
	stream << "Width:  " << ob.width_ << endl;
	stream << "Height: " << ob.height_ << endl;
	stream << "Data: " << ob.rawData_.size() << endl;
	return stream;
}

void operator >> (const YAML::Node& node,YmlObject& y) {
	node["width"]  >> y.width_;
	node["height"] >> y.height_;
	node["data"]   >> y.rawData_;
}


void YmlObject::read() {
	std::ifstream fin(path_.c_str());
	YAML::Parser parser(fin);
	YAML::Node doc;
	parser.GetNextDocument(doc);
	doc["depth"] >> *this;
}


void YmlObject::getPointCloud(pcl::PointCloud<pcl::PointXYZ>& cloud, int xmin, int xmax, int ymin, int ymax) {

	//cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;
	cloud.width    = (xmax - xmin + 1 ) * (ymax - ymin + 1); // +1 means the borders of the bounding box are included.
	cloud.height   = 1;
	cloud.is_dense = true;  //Not important, for security of other processing maybe is useful to set it to false. http://www.pcl-users.org/warning-is-dense-misused-td2029417.html
	cloud.points.resize (cloud.width * cloud.height);
	
	float val;
	int i;			// i is the index of the full image to get the depth. 
	int index = 0;	// index is the counter to store the pointcloud.
	for (int row = ymin; row <= ymax; ++row) { 		// <= means the borders of the bounding box are included.
		for (int col = xmin; col <= xmax; ++col) { 
			i = row*640 + col;
			
			//Conversion to meters
			if (rawData_[i] < 2047) 
				val = 0.1236 * tanf(rawData_[i] / 2842.5 + 1.1863);					// http://openkinect.org/wiki/Imaging_Information
			else
				val = 0;
			
			//Conversion to XYZ
			cloud.points[index].x = (col - 339.30780975300314) * val / 594.21434211923247;   // http://nicolas.burrus.name/index.php/Research/KinectCalibration
			cloud.points[index].y = (row - 242.73913761751615) * val / 591.04053696870778;
			cloud.points[index].z = val;
			index++;
		}
	}
}
