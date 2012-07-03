#ifndef FILE_H_
#define FILE_H_

#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

/**
 * @author Javier V. Gómez - MRGroup - UPM.
 *
 * Class to store the features of a file based on Boost  * libraries. 
 * Thus, it is necessary to have these libraries installed.
 * 
 * This class is not 100% finished. It has only a few methods and it 
 * we be improved continuosly.
 * */

class File
{
public:

	/**
	 * Not used.
	 * */
	File();
	
	/**
	 * Overload of the constructor in order to get automatically all the
	 * features of a file giving the path to the file.
	 * 
	 * @param p path of the file.
	 * */
	File(path p);
	
	/**
	 * Not used.
	 * */
	virtual ~File();
	
	/**
	 * Method to set the name
	 * @param n name of the file.
	 * @see getName()
	 * */
	void setName(string n) 			{name=n;}
	
	/**
	 * Method to set the path
	 * @param p path of the file.
	 * @see getPath()
	 * */
	void setPath(string p) 			{ppath=p;}
	
	/**
	 * Method to set the size
	 * @param s size of the file.
	 * @see getSize()
	 * */
	void setSize (unsigned int s) 	{size=s;}
	
	/**
	 * Method to get the name of the file.
	 * @return name of the file as a string.
	 * @see setName()
	 * */
	string getName() 			{return name;}
	
	/**
	 * Method to get the path of the file.
	 * @return path of the file as a string.
	 * @see setPath()
	 * */
	string getPath() 			{return ppath;}
	
	/**
	 * Method to get the size of the file.
	 * @return size of the file in bits.
	 * @see setSize()
	 * */
	unsigned int getSize() 		{return size;}
	
private:

	string name;
	string ppath;
	unsigned int size;

};

#endif /* FILE_H_ */
