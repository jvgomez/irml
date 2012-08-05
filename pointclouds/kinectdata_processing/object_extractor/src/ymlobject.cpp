#include "ymlobject.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#include "yaml-cpp/yaml.h"

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
	
	//Not elegant but I cannot find unkown labels with yaml-cpp
	if(const YAML::Node *foo = doc.FindValue("depth") ) {  //If not depth, it is something like kinect#_d with data in meters.
		is_raw_ = 1;
		*foo >> *this;
	}
	else {
		is_raw_ = 0;
		int kin_count = 0;
		bool found = false;
		 						
		while (!found) { 		
			stringstream label;											// kinect299_d is the highest label in img_0266.xml
			label << "kinect" << kin_count << "_d";						//kinect0_d in img_0064.xml
			if (const YAML::Node* bar = doc.FindValue(label.str())) {
				*bar >> *this;
				found = true;
			}
			else
				kin_count++;	
		}
	}
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
			
			if (is_raw_) {
				//Conversion to meters
				if (rawData_[i] < 2047) 
					val = 0.1236 * tanf(rawData_[i] / 2842.5 + 1.1863);					// http://openkinect.org/wiki/Imaging_Information
				else
					val = 0;
			}
			else
				val = rawData_[i];
			
			//Conversion to XYZ
			cloud.points[index].x = (col - 339.30780975300314) * val / 594.21434211923247;   // http://nicolas.burrus.name/index.php/Research/KinectCalibration
			cloud.points[index].y = (row - 242.73913761751615) * val / 591.04053696870778;
			cloud.points[index].z = val;
			index++;
		}
	}
}
