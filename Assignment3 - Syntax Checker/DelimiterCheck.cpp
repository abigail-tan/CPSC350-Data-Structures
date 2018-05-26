#include <iostream> 
#include <fstream>
#include <stack>
#include <string>
#include "DelimiterCheck.h"
#include "GenStack.h"

//constructor
DelimiterCheck::DelimiterCheck()
{

}

DelimiterCheck::~DelimiterCheck()
{

}

//checks to make user user inputted file is valid
string DelimiterCheck::checkFile(string file)
{
	ifstream f(file.c_str());
	while(!(f.good())){
		cout<<"Not a valid file.\nEnter a valid file name: ";
		cin >> file;
		ifstream f(file.c_str());
		if(f.good())
			return file;
		else{
			cin.clear();		
			cin.ignore(10000,'\n');
			continue;
		}
	}
	return file;
}

//checks delimeters in the file
int DelimiterCheck::checkSyntax(string file)
{
	ifstream myFile;
	GenStack<char> s(15);
	bool keepGoing = true; 
	int lineCount = 0;

	while(keepGoing == true){
		string code;
		myFile.open(file.c_str());
		if(myFile.is_open()){
		   	while(!myFile.eof()){
		   		lineCount++;
		   		getline(myFile, code);
		   		for(double i = 0; i < code.size(); i++)
		   		{
		   			if(code[i]=='{' || code[i]=='[' || code[i]=='(')
		   				s.push(code[i]);
		   			else if(code[i]=='}')
		   			{
		   				if(s.isEmpty()){
		   					cout<<"Line "<<lineCount<<": expected { but found "<<code[i]<<" instead.\n";
		   					return 0; 
		   				}	
		   				if(s.peek() != '{'){
		   					cout<<"Line "<<lineCount<<": expected { but found "<<code[i]<<" instead.\n";
		   					return 0; 
		   				}
		   				s.pop(); 
		   			}
		   			else if(code[i]==']')
		   			{
		   				if(s.isEmpty()){
		   					cout<<"Line "<<lineCount<<": expected [ but found "<<code[i]<<" instead.\n";
		   					return 0; 
		   				}	
		   				if(s.peek() != '['){
		   					cout<<"Line "<<lineCount<<": expected [ but found "<<code[i]<<" instead.\n";
		   					return 0; 
		   				}
		   				s.pop();
		   			}
		   			else if(code[i]==')')
		   			{
		   				if(s.isEmpty()){
		   					cout<<"Line "<<lineCount<<": expected ( but found "<<code[i]<<" instead.\n";
		   					return 0; 
		   				}	
		   				if(s.peek() != '('){
		   					cout<<"Line "<<lineCount<<": expected ( but found "<<code[i]<<" instead.\n";
		   					return 0; 
		   				}
		   				s.pop();
		   			}
		   		}
		   	}
		}
		myFile.close();

		//if the stack is empty, that means every symbol matched && code is good to go 
		if(s.isEmpty())
		{	
			char cont; 
			cout <<"Your code is good to go! No syntax errors existed.\n";
			cout <<"Would you like to check another file? (Y/N) ";
			cin >> cont;
			if(tolower(cont) == 'y'){ 
				cout << "Enter the name for your file: ";
				cin >> file;
				file = checkFile(file);
			}
			else{
				cout<<"Goodbye!";
				keepGoing = false;
			}
		}
		
		//if stack isn't empty, extra brackets existed/were never matched
		else
		{
			cout<<"End of File Error: found delimiter "<<s.peek()<<" without its matching delimiter.\n";
			keepGoing = false; 
		}
	}
	return 0;
}