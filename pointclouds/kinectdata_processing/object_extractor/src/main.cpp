#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include <boost/filesystem.hpp>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/console/time.h>

#include "ymlobject.h"
#include "scene.h"
#include "diranalyzer.h"
#include "file.h"

using namespace std;

int main(int argc, char** argv) {
	if (argc == 3) 
		cout << "\33[4;34m" << "Reading folder:" << "\33[0m" << " " << argv[2] << endl;
	else {
		cerr << "\33[31m" << "To run: ./3dobjext <path_to_yml_folder> <path_to_xml_folder>" << "\33[0m" << endl;
		return 0;
	}
	pcl::console::TicToc timer;
	
	DirAnalyzer	dirAnalyzer;
	vector<File> ymlFiles;
	vector<File> xmlFiles;
	
	dirAnalyzer.getFiles(argv[2], xmlFiles);
	
	pcl::PCDWriter writer;
	
	fstream logger ("../output/objects.txt", fstream::out | fstream::trunc);

	for (vector<File>::iterator it (xmlFiles.begin()); it!=xmlFiles.end(); ++it) { 
		timer.tic();
		//Read the scene means reading the XML and its objetcs
		Scene s(it->getPath()); // The creation of the object already reads the file.
								//Each scene has one file and several objects
		//cout << s;
		
		//Read the YAML (.yml) file corresponding to the xml read.
		string name = it -> getName();
		name.erase(name.end()-4, name.end()); //Removing the xml extension.
	
		stringstream ymlpath;
		ymlpath << argv[1] << name << ".yml"; //Creating the yml path.
		YmlObject yml (ymlpath.str()); // The creation of the object already reads the file.
		//cout << yml;
		
		//The 3D pointcloud is obtained from every object labeled in a given scene (xmlfile).
		pcl::PointCloud<pcl::PointXYZ> cloud;
		int count = 0;
		for (vector<XmlObject>::iterator it2 (s.objects.begin()); it2!=s.objects.end(); ++it2) {
			yml.getPointCloud(cloud, it2->xmin, it2->xmax, it2->ymin, it2->ymax);
			stringstream objname;
			objname << "../output/" << name << "_" << setfill ('0') << setw(2) << count << ".pcd";
			writer.write<pcl::PointXYZ> (objname.str(), cloud, true);

			//Logging into a textfile
			logger << count << "\t" << name << "\t" << it2->type << "\t" << it2->is_occluded << "\t" << it2->is_difficult << endl;
			
			count++;
		}
		
		cout << "\33[1;32m" << name << " \33[0m";
		timer.toc_print();
	}

	logger.close();	
	return 0;
}
