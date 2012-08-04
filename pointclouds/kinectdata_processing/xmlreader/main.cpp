#include <iostream>
#include <string>
#include <vector>
#include "Markup.h"

using namespace std;

typedef struct {
	string type;
	float xmin, xmax, ymin, ymax;
	bool is_difficult;
	bool is_occluded;
} Object;

ostream& operator << (ostream& stream, Object& ob) {
	stream << "Object type: " << ob.type << endl;
	stream << "Bounding box X:\t" << ob.xmin << "\t" << ob.xmax << endl;
	stream << "Bounding box Y:\t" << ob.ymin << "\t" << ob.ymax << endl;
	stream << "Difficult: " << ob.is_difficult << endl;
	stream << "Occluded: " << ob.is_occluded << endl << endl;
	
	return stream;
}


int main()
{
	CMarkup xml;
	xml.Load( "img_0848.xml" );
	
	xml.FindElem(); // root ORDER element
	xml.IntoElem(); // inside ORDER
	
	vector<Object> objects;
	
	while ( xml.FindElem("object") )	{
		Object ob;
		
		xml.IntoElem();
		
		xml.FindElem( "name" );
		ob.type = MCD_2PCSZ(xml.GetData());
		
		xml.FindElem( "bndbox" );
		xml.IntoElem();
			xml.FindElem( "xmax" );
			ob.xmax = atoi( MCD_2PCSZ(xml.GetData()) );
			xml.FindElem( "xmin" );
			ob.xmin = atoi( MCD_2PCSZ(xml.GetData()) );
			xml.FindElem( "ymax" );
			ob.ymax = atoi( MCD_2PCSZ(xml.GetData()) );
			xml.FindElem( "ymin" );
			ob.ymin = atoi( MCD_2PCSZ(xml.GetData()) );
		xml.OutOfElem();
		
		xml.FindElem( "difficult" );
		ob.is_difficult = atoi( MCD_2PCSZ(xml.GetData()) );
		
		xml.FindElem( "occluded" );
		ob.is_occluded = atoi( MCD_2PCSZ(xml.GetData()) );
		
		xml.OutOfElem();
		
		objects.push_back(ob);
	}

	for (vector<Object>::iterator it = objects.begin(); it != objects.end(); ++it) 
		cout << *it;

	return 0;
}
