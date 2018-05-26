#include <iostream>
#include <string>
#include <stdlib.h>
#include "GenStack.h"
#include "DelimiterCheck.h"

using namespace std;

int main(int argc, char** argv) {

	//makes sure the user runs the code with a file 
	if(!(argc==2)) 
	{
		cout<<"Error: Need either more or less arguments."<<endl;
		exit(0);
	}

	string file = argv[1];
	DelimiterCheck d;
	file = d.checkFile(file);
	d.checkSyntax(file);

	return 0;
}