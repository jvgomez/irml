#include "diranalyzer.h"

DirAnalyzer::DirAnalyzer()
{
	
}


DirAnalyzer::~DirAnalyzer()
{
	
}
	

void DirAnalyzer::getFiles(path folder_path, vector<File> & files)
{
	vector<path> files_to_read = readFolder(folder_path);	

	for (vector<path> ::const_iterator it (files_to_read.begin()); it != files_to_read.end(); ++it)
	{	
		path p=*it;
		try
		{
			if (is_regular_file(p))        // is p a regular file?   
			{
				File new_file(p);
				/*File new_file;
				new_file.setName(p.filename());
				new_file.setPath(p.string());
				new_file.setSize(file_size(p));*/
				files.push_back(new_file);
			}

			else if (is_directory(p))      // is p a directory?
			{
			getFiles(p, files);
			}	
		}
	
		catch (const filesystem_error& ex)
		{
			cout << ex.what() << '\n';
			exit(1);
		}
	}
}


vector<path> DirAnalyzer::readFolder(path p)
{
	try
	{
		vector<path> objects_in_folder;
	
        typedef vector<path> vec;           // store paths
        vec v;                                

        copy(directory_iterator(p), directory_iterator(), back_inserter(v));
        sort(v.begin(), v.end());			// sort paths
        
        for (vec::const_iterator it (v.begin()); it != v.end(); ++it)
        {
			path fh = *it;
			objects_in_folder.push_back(fh.string());
		}	
		
		return objects_in_folder;
	}

	catch (const filesystem_error& ex)
	{
		cout << ex.what() << '\n';
		exit(1);
	}
	
}

