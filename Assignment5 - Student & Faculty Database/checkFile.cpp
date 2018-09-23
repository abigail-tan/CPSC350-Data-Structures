#include <iostream>
#include <fstream>
#include <string>
#include "checkFile.h"
using namespace std;

checkFile::checkFile()
{

}

checkFile::checkFile(string name)
{
	name = fileName; 
	fileExists(fileName);
}
checkFile::~checkFile()
{

}

bool checkFile::fileExists(string name)
{
	ifstream file;
	bool exists = false;  
	file.open(name.c_str()); 
	if(file.fail())
	{
		cout<<"file dne"<<endl;
		return exists; 
	}
	else{
		//go to reading?
		file.close(); 
		exists = true; 
		return exists; 
	}
}