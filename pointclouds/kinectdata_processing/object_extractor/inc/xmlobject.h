/*******************************************************
* Class to store the data of an object in a 
* kinectdata.com database scene.
********************************************************/

#ifndef XMLOBJECT_H_
#define XMLOBJECT_H_

#include <string>

class XmlObject{
	friend std::ostream& operator << (std::ostream& , XmlObject&);
	
public:
	XmlObject() 	{ }
	~XmlObject() 	{ }
	
//TODO: private:
	std::string type;
	float xmin, xmax, ymin, ymax;
	bool is_difficult;
	bool is_occluded;
};

#endif
