#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/filesystem.hpp>

#include "diranalyzer.h"
#include "file.h"
#include "Markup.h"

using namespace std;

int main(int argc, char** argv) {
	if (argc == 2) 
		cout << "\33[4;34m" << "Reading folder:" << "\33[0m" << " " << argv[1] << endl;
	else {
		cerr << "\33[31m" << "To run: ./xmlparser <path_to_xml_folder>" << "\33[0m" << endl;
		return 0;
	}
	
	DirAnalyzer	dirAnalyzer;
	vector<File> xmlFiles;
	
	dirAnalyzer.getFiles(argv[1], xmlFiles);
	
	fstream logger ("../output/objects.txt", fstream::out | fstream::trunc);

	for (vector<File>::iterator it (xmlFiles.begin()); it!=xmlFiles.end(); ++it) {  // " For every scene..."
		string filepath = it->getPath();
		string filename = it -> getName();
		filename.erase(filename.end()-4, filename.end()); 
		
		CMarkup xml;
		xml.Load( filepath );
		
		xml.FindElem(); // root element
		xml.IntoElem(); // inside root
		
		while ( xml.FindElem("object") ) {
			xml.IntoElem();
			xml.FindElem( "name" );
			string ob = MCD_2PCSZ(xml.GetData());
			xml.OutOfElem();
			logger << ob << "\t" ;
		}
		
		logger << endl;
	}
	
	return 0;
}
