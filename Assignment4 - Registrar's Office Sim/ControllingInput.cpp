#include "ControllingInput.h"

using namespace std;

ControllingInput::ControllingInput(){}
ControllingInput::~ControllingInput(){}

string ControllingInput::ValidatePath(string message) //checks whether file exists 
{
	//cout<<message;
	string filePath;
	while(true)
	{
		cout << message;
		getline(cin, filePath);
		struct stat buffer; 
		if (!(stat(filePath.c_str(),&buffer) == 0)) //checks whether the file exists 
		{
			cout<<"IO Error: File does not exist."<<endl;
			continue;
		}
		else
		{
			//cout<<"File is good"<<endl;
			break;
		}
	}
	return filePath;
}

string ControllingInput::ValidateFile(string inFile) //validates that file is good
{
	struct stat buffer;
	if (!( stat( inFile.c_str(), &buffer ) == 0))  // checks existence of file
	{
		return "IO Error: File does not exist.";
	}
	else
	{
		return inFile;
	}

}