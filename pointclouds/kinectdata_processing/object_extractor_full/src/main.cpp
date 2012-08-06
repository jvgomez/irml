#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include <boost/filesystem.hpp>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/console/time.h>

#include <Magick++.h>

#include "ymlobject.h"
#include "scene.h"
#include "diranalyzer.h"
#include "file.h"
#include "imgcoord.h"

using namespace std;
using namespace Magick;

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

	for (vector<File>::iterator it (xmlFiles.begin()); it!=xmlFiles.end(); ++it) {  // " For every scene..."
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
		
		//A 3D pointcloud is obtained and processed from every object labeled in a given scene (xmlfile).
		int count = 0;
		for (vector<XmlObject>::iterator it2 (s.objects.begin()); it2!=s.objects.end(); ++it2) { // "For every labeled object in the scene..."
			pcl::PointCloud<pcl::PointXYZ> cloud;
			vector<ImgCoord> pixels;  //It stores the initial row, col and depth of the pixels.
			yml.getPointCloud(cloud, pixels, it2->xmin, it2->xmax, it2->ymin, it2->ymax);
			
			/* 
			 * Point Cloud Processing and Segmentation
			 * */
			 
			//Saving the object.
			stringstream objname;
			objname << "../output/" << name << "_" << setfill ('0') << setw(2) << count << ".pcd";
			writer.write<pcl::PointXYZ> (objname.str(), cloud, true);

			//Logging into a textfile.
			logger << count << "\t" << name << "\t" << it2->type << "\t" << it2->is_occluded << "\t" << it2->is_difficult << endl;
			
			//Saving into a grayscale image.
				//Looking for depth range of the object.
				float maxdepth = 0;  //Raw values.
				float mindepth = 2047;
			for(vector<ImgCoord>::iterator it = pixels.begin(); it != pixels.end(); ++it) {
				if(it->depth_ > maxdepth)
					maxdepth = it->depth_;
				if(it->depth_ < mindepth)
					mindepth = it->depth_;
			}

			Geometry imgsize(it2->xmax - it2->xmin + 1, it2->ymax - it2->ymin + 1);
			Image gray(imgsize, "black");
			gray.type( GrayscaleType );
			
			stringstream imgname;
			imgname << "../output/images/" << name << "_" << setfill ('0') << setw(2) << count << ".png";
				//Saving grayscale points in their corresponding pixels.
			for(vector<ImgCoord>::iterator it = pixels.begin(); it != pixels.end(); ++it) {
				int row = it->row_;
				int col = it->col_;
				//Scaling depths (linearly) to grays between 0.9 and 1 (to clearly difference between background, 0, and far objects, 0.9).
				gray.pixelColor(col - it2->xmin ,row - it2->ymin, ColorGray(-0.9/(maxdepth-mindepth) * (it->depth_-mindepth) + 1));
			}
			gray.write(imgname.str());
			
			count++;
		}
		
		cout << "\33[1;32m" << name << " \33[0m";
		timer.toc_print();
	}

	logger.close();	
	return 0;
}
