#include "scene.h"
#include "Markup.h"
#include <iostream>

using namespace std;

ostream& operator << (ostream& stream, Scene& s) {
	stream << "\33[4;33m" << "Scene:" << "\33[0m" << " "  << s.path_ << endl;
	for (vector<XmlObject>::iterator it (s.objects.begin()); it!=s.objects.end(); ++it)
		stream << *it;

	return stream;
}

void Scene::readScene () {
	CMarkup xml;
	xml.Load( path_ );
	
	xml.FindElem();
	xml.IntoElem();
	
	while ( xml.FindElem("object") )	{
		XmlObject ob;
		
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
}
