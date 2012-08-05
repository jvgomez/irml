#include <cmath>

class DepthRaw {
	
	friend void operator >> (const YAML::Node& node, DepthRaw& m);
	friend std::ostream &operator<<(std::ostream &stream, DepthRaw& m);
	
public:
	DepthRaw(unsigned int w, unsigned int h, const std::vector<float>& d): width_(w), height_(h), rawdata_(d) { raw2depth(); }
	DepthRaw(const DepthRaw&) { /* copy */ }
	DepthRaw() { }
	~DepthRaw() { /* delete */ }
	DepthRaw& operator = (const DepthRaw& m) {	width_ = m.width_;
												height_ = m.height_;
												rawdata_ = m.rawdata_;
												raw2depth();}
	void raw2depth() {
		for (std::vector<float>::iterator it = rawdata_.begin(); it != rawdata_.end(); ++it) {
			float val;
			if (*it < 2047) 
				val = 0.1236 * tanf(*it / 2842.5 + 1.1863);					// http://openkinect.org/wiki/Imaging_Information
				//val = 1.0 / (*it * -0.0030711016 + 3.3309495161);   		// http://nicolas.burrus.name/index.php/Research/KinectCalibration
			else
				val = 0;
				
			depthdata_.push_back(val);					
		}	
	}
	
	std::vector<float> getDepthData() const {return depthdata_;}
												
	//TODO: private:									
	unsigned int width_, height_;
	std::vector<float> rawdata_;
	std::vector<float> depthdata_;
};


void operator >> (const YAML::Node& node, DepthRaw& m) {
		unsigned int width, height;
		std::vector<float> rawdata;
		node["width"]  >> width;
		node["height"] >> height;
		node["data"]   >> rawdata;
		m = DepthRaw(width, height, rawdata);
	}

std::ostream &operator<<(std::ostream &stream, DepthRaw& m) 
	{ 
		stream << "Width: " << m.width_ << std::endl; 
		stream << "Height: " << m.height_ << std::endl;
		stream << "Depth Data size: " << m.depthdata_.size() << std::endl;
		/*for (std::vector<float>::iterator it = m.depthdata_.begin(); it != m.depthdata_.end(); ++it) {
			stream << *it << " ";
		}*/
		stream << std::endl;
		return stream;  // return the stream 
	} 
 
