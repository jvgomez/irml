#include "ymlobject.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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


void YmlObject::getPointCloud(pcl::PointCloud<pcl::PointXYZ>& cloud, vector<ImgCoord> & pixels, int xmin, int xmax, int ymin, int ymax) {
	int i;			// i is the index of the full image to get the depth. 
	for (int row = ymin; row <= ymax; ++row) { 		// <= means the borders of the bounding box are included.
		for (int col = xmin; col <= xmax; ++col) { 
			i = row*640 + col;
			
			float val = 0;
			if (is_raw_) {
				//Conversion to meters
				if (rawData_[i] < 2047) 
					val = 0.1236 * tanf(rawData_[i] / 2842.5 + 1.1863);					// http://openkinect.org/wiki/Imaging_Information
				else
					val = 0;
			}
			else
				val = rawData_[i];
			
			if (val > 0.1) {   //We only save those pixels with Z(depth) > 0.1. The others will be erased.
				ImgCoord pix;
				pix.row_ = row;
				pix.col_ = col;
				pix.depth_ = val;
				pixels.push_back(pix);
			}
		}
	}
	
	cloud.width    = pixels.size(); // +1 means the borders of the bounding box are included.
	cloud.height   = 1;
	cloud.is_dense = true;  //Not important, for security of other processing maybe is useful to set it to false. http://www.pcl-users.org/warning-is-dense-misused-td2029417.html
	cloud.points.resize (cloud.width * cloud.height);
	
	int index = 0;
	for(vector<ImgCoord>::iterator it = pixels.begin(); it != pixels.end(); ++it) {
		//Conversion to XYZ
		cloud.points[index].x = (it->col_ - 339.30780975300314) * it->depth_ / 594.21434211923247;   // http://nicolas.burrus.name/index.php/Research/KinectCalibration
		cloud.points[index].y = (it->row_ - 242.73913761751615) * it->depth_ / 591.04053696870778;
		cloud.points[index].z = it->depth_;
		index++;
	}
}
