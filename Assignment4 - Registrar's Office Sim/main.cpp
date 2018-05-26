//Assignment 4 - Registrar's Office Simulation

#include <iostream>
#include "ControllingInput.h"
#include "RunFile.h"

using namespace std;

int main( int argc, char** argv)
{

	string inFile;
	ControllingInput ci;
	RunFile rf;

	cout << "You have entered " << argc
	     << " arguments: " << endl;

	for (int i = 0; i < argc; ++i)
		cout << argv[i] << endl;

	// determine if input file was given, otherwise ask for it
	// once an input file is received then validate that it exists
	if ( argc == 1 ) 		// no input file was given for simulation
	{ 
		cout << "No input parameters provided\n" << endl;
		inFile = ci.ValidatePath("Enter name of input file for simulation: \n");
	}
	else if ( argc == 2 )
	{
		inFile = argv[1];
		//cout << "Input file: " << inFile << endl;
		string test = ci.ValidateFile(inFile);

		cout << test << endl;

		if ( test == "IO Error: File does not exist." )
		{
			inFile = ci.ValidatePath("Enter the name of input file for simulation: \n");
		}
		else
		{
			inFile = test;
		}
	}

	cout << "Ready to process  -  Simulation file: " << inFile << endl;

	rf.read( inFile );
	rf.simulation();

	return 0;

}