#ifndef CONTROLLINGINPUT_H
#define CONTROLLINGINPUT_H
#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h> //for atoi function that converts string to int
#include <cctype>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <string>

using namespace std;

class ControllingInput
{
	public:
		ControllingInput();
		~ControllingInput();
		//int AskOptionInput(int options, string message, string name);
		string ValidatePath(string message); //reads file
		string ValidateFile(string inFile);
		//int AskRow(); //gets height
		//int AskColumn(); //gets width
		//double AskPercentage(); //gets density and converts to decimal
		//bool IsBadInt(string inputStr);
		//string promptPath();
		//int height; 
		//int width;
		//int mode;
		//double density;
		
	//private:		
		//int outputNum;
		//string OutputFile;

};

#endif