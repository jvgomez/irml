#include "xmlobject.h"
#include <iostream>

using namespace std;

ostream& operator << (ostream& stream, XmlObject& ob) {
	stream << "Object type: " << ob.type << endl;
	stream << "Bounding box X:\t" << ob.xmin << "\t" << ob.xmax << endl;
	stream << "Bounding box Y:\t" << ob.ymin << "\t" << ob.ymax << endl;
	stream << "Difficult: " << ob.is_difficult << endl;
	stream << "Occluded: " << ob.is_occluded << endl << endl;
	return stream;
}
