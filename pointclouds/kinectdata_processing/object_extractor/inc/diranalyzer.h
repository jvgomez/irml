#ifndef DIR_ANALYZER_H_
#define DIR_ANALYZER_H_

#include <iostream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "file.h"

using namespace boost::filesystem;
using namespace std;

/**
 * @author Javier V. Gómez - MRGroup - UPM.
 *
 * Class to encapsulate directory navigation and usage based on Boost
 * libraries. Thus, it is necessary to have these libraries installed.
 * 
 * This class is not 100% finished. It has only a few methods and it 
 * we be improved continuosly.
 * */

class DirAnalyzer
{
public:
	/**
	 * Not used.
	 */
	DirAnalyzer();
	/**
	 * Not used.
	 */
	virtual ~DirAnalyzer();
	
	/**
	 * This method returns all the files existing in a folder and its
	 * subfolders. It is based in a depth first search.
	 * 
	 * @param folder_path is the root path to start the search.
	 * @param files file structs vector in which the files data will be
	 * stored. It is originally path type, but if a char * parameter is
	 * given it will convert it automatically.
	 * 
	 * @return It has no return, but the number of files read can be 
	 * obtained through the size of files vector.
	 * 
	 * @see readFolder()
	 */
	void getFiles(path folder_path, vector<File> & files);
	
	/**
	 * Method to obtain all the items existing in a folder. This method
	 * is used by getFiles() to run a depth first search.
	 * 
	 * @param p is the path of the folder it is wanted to be read.
	 * 
	 * @return vector of paths (files or folders) included in the given
	 * path.
	 * 
	 * @see getFiles()
	 * */
	vector<path> readFolder (path p);

	private:
	
};

#endif /* DIR_ANALYZER_H_ */
