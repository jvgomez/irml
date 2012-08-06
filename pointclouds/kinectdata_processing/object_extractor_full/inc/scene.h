/*******************************************************
* Class to extract the information of the objects of the
* kinectdata.com database scenes by parsing the xml files.
********************************************************/

#ifndef SCENE_H_
#define SCENE_H_

#include <string>
#include <vector>
#include "xmlobject.h"

class Scene{
	friend std::ostream& operator << (std::ostream& , Scene&);
	
public:
	Scene() 	{ }
	Scene(std::string p): path_(p) {readScene();}
	~Scene() 	{ }
	
	void readScene ();
	
//TODO: private:
	std::vector<XmlObject> objects;
	std::string path_;
};

#endif
