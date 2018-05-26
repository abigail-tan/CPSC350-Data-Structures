#include "UserInput.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std; 

UserInput::UserInput()
{
	height = 0; 
	width = 0; 
	density = 0; 
}

UserInput::~UserInput(){
}

int UserInput::getFileType()
{
	cout<<"Enter '0' if you would like to use your own map file and '1' if you want a random assignment: ";
	cin >> fileType; 

	//error checking
	while(!(cin.good()))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		UserInput::getFileType();
	}

	if(fileType == 0)
	{
		filePath = UserInput::validFilePath();
		UserInput::readFile(filePath);
	}
	else if(fileType==1)
	{
		cout <<"Enter dimensions for your world."<<endl
			<<"Enter the number of rows (height): ";
		cin >> height; 
		height = UserInput::validIntInput(height);
		cout << "Enter the number of columns (width): ";
		cin >> width; 
		width = UserInput::validIntInput(width);
		cout << "Enter a decimal between 0 and 1: ";
		cin >> density; 
		density = UserInput::validDoubleInput(density);
	}
	else
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();
		cin.ignore(1,' ');
		UserInput::getFileType();
	}

	return fileType;
}

void UserInput::readFile(string filePath)
{
	string myString;
	ifstream myFile;
	int lineCount = 0;

	//open file to get rows and columns
	myFile.open(filePath.c_str());
	if(myFile.is_open())
	{
	   	while(!myFile.eof())
	   	{
	   		cout<<myString;
	   		lineCount++;
	   		getline(myFile, myString);
	   		if(lineCount == 1)
	   			height = atoi(myString.c_str());
	   		else if(lineCount==2)
	   			width = atoi(myString.c_str());
	   	}
	}
	myFile.close();
}
 
int UserInput::gameMode()
{
	int mode; 
	cout << "1. Classic Mode\n2. Doughnut Mode\n3. Mirror Mode"<<endl;
	cout << "Enter the number of what game mode you want to do: ";
	cin >> mode;

	//error checking
	while(!(cin.good()) || mode > 3 || mode <= 0)
	{
		cout << "Not a valid response. Try again."<<endl;
		cout << "Enter the number of what game mode you want to do.\n";
		cin.clear();
		cin.ignore(10000,'\n');
		cin >> mode;
	}

	return mode;
}

int UserInput::getOutputMethod()
{
	cin.clear();
	cin.ignore(10000,'\n');
	int outputMethod = 0; 
	cout<<"Enter '0' if you want to print through the terminal and pause after every generation\nand '1' if you want them all to print to a file: ";
	cin >> outputMethod; 

	//error checking
	while(!(cin.good()))
	{
		if(!(cin.good()))
		{
			cin.clear();
			cin.ignore(10000,'\n');
		}
		cout<<"Not a valid response. Try again."<<endl;
		cout<<"Enter '0' or '1': ";
		cin >> outputMethod;
	}

	if(outputMethod == 0 || outputMethod == 1)
		return outputMethod; 
	else if(outputMethod != 1)
	{
		cout<<"Not a valid response. Try again."<<endl;
		cout<<"Here's a reminder of your options:\n";
		UserInput::getOutputMethod();
	}

}

//check whether the file path exists or not 
//got from http://www.cplusplus.com/forum/general/1796/
string UserInput::validFilePath()
{
	while(true){
		string testFilePath;
		cout << "Enter the file path: ";
		cin >> testFilePath;
		ifstream ifile(testFilePath.c_str());
		if(ifile)
			return testFilePath;
		else{
			cout<<"Not a valid file path. Try again\n";
			cin.clear();
			cin.ignore(10000,'\n');
		}
	}
}

int UserInput::validIntInput(int x)
{
	int y = x;

	while(!(cin.good()) || y < 3)
	{
		if(!(cin.good()))
			cout << "Not a valid response. Try again."<<endl;
		else if(y < 3)
			cout << "That number is too low. You need at least a 3x3 grid. Try again."<<endl;
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Enter the number: "<<endl;
		cin >> y;
	}
	return y;
}

double UserInput::validDoubleInput(double x)
{
	double y = x;

	while(y <= 0 || y >= 1 || !(cin.good()))
	{
		if(!(cin.good()))
			cout<<"Not a valid response. Try again."<<endl;
		if(y >= 1)
			cout << "That number is too high. Try again."<<endl;
		else if(y <= 0)
			cout << "That number is too low. Try again."<<endl;
		cin.clear();
		cin.ignore(10000,'\n');
		cout << "Enter a decimal between 0 and 1: ";
		cin >>y; 
	}

	return y; 
}

string UserInput::getFilePath(){
	return filePath;
}

int UserInput::getHeight(){
	return height; 
}

int UserInput::getWidth(){
	return width;
}
		
double UserInput::getDensity(){
	return density; 
}