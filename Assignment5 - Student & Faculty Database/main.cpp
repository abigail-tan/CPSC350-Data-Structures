#include <iostream>
#include <fstream>
#include <stdio.h>
//#include "BST.h"
#include "checkFile.h"
#include "Faculty.h"
#include "Student.h"
#include "Simulation.h"
using namespace std; 
int main()
{

	checkFile checkFaculty; 
	checkFile checkStud; 
	if((checkFaculty.fileExists("facultyTable.txt"))&&(checkStud.fileExists("studentTable.txt")))
	{

		Simulation s; 
	}
	else
	{
		cout<<"No records were found"<<endl;
	}
}
