#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include "Faculty.h"
using namespace std; 
Faculty::Faculty()
{
	adviseesID = new int[5]; 
	maxSize = 5; 
	for (int i = 0; i < 5; i++)
    {
        adviseesID[i] = -1;
    }
    numAdvisees=0;
}

Faculty::~Faculty()
{

}

void Faculty::increaseAdvisees()
{
	numAdvisees++; 
	cout<<numAdvisees<<endl;
}

Faculty::Faculty(int id_)
{
	
	id = id_;
	name = "";
	level = "";
	dept = "";
	adviseesID = new int[5]; 
	maxSize = 5; 
	for (int i = 0; i < 5; i++)
    {
        adviseesID[i] = -1;
    }
	numAdvisees = 0;
}

Faculty::Faculty(int id_, string name_, string level_, string dept_)
{
	id = id_; 
	name = name_; 
	level = level_; 
	dept = dept_;
	adviseesID = new int[5]; 
	maxSize = 5; 
	for (int i = 0; i < 5; i++)
    {
        adviseesID[i] = -1;
    }
    numAdvisees=0; 

}

void Faculty::clearFile()
{
	ofstream file; 
	file.open("facultyTable.txt"); 
	file.clear(); 
	file.close(); 
}

ostream& operator<<(ostream& os, const Faculty &faculty)
{
	os<<faculty.id; 
	return os; 
}

bool operator> (const Faculty &f1, const Faculty &f2)
{
	return (f1.id > f2.id); 
}

bool operator< (const Faculty &f1, const Faculty &f2)
{
	return (f1.id < f2.id); 
}

bool operator>= (const Faculty &f1, const Faculty &f2)
{
	return (f1.id >= f2.id); 
}

bool operator<= (const Faculty &f1, const Faculty &f2)
{
	return (f1.id <= f2.id);
}

bool operator== (const Faculty &f1, const Faculty &f2)
{
	return (f1.id == f2.id); 
}

bool operator!= (const Faculty &f1, const Faculty &f2)
{
	return (f1.id != f2.id);
}

int Faculty::countAdvisees()
{
	int adviseeCount=0; 
	for (int i=0; i<maxSize; i++)
	{
		if(adviseesID[i]!=-1)
			adviseeCount++; 
		
	}
	return adviseeCount;
}

void Faculty::printFacultyMember() 
{
  cout << "ID:  " << id << " | ";
  cout << "Name: " << name << " | ";
  cout << "Level: " << level << " | ";
  cout << "Department: " << dept << " | ";
  printAdvisees();
  cout << endl;
}

void Faculty::printAdvisees() 
{
  if(numAdvisees == 0) 
    cout << "None";
  else 
  {
  	cout << "Advisee Id(s): ";
  	for(int i=0;i<5;i++)
  	{
  		if(adviseesID[i] == -1)
    		continue;
    	else
       		cout << adviseesID[i];
	       	if((i < maxSize)) 
	       		cout  << ", ";
  	}
  }
  int count = countAdvisees(); 
  //cout<<endl<<"Advisee Count: "<<count<<endl;
}


void Faculty::writeFacultyMember() 
{
	ofstream file; 
	file.open("facultyTable.txt",std::ios_base::app);
  file << id << "|";
  file << name << "|";
  file << level << "|";
  file << dept << "|";
  int count; 
  count = countAdvisees(); 
  file <<count<<"|"; 

   if(numAdvisees == 0) 
 	file<<"0000"; 
  else 
  {
  	for(int i=0;i<5;i++)
  	{
  		if(adviseesID[i] == -1)
    		continue;
    	else
       		file << adviseesID[i];
	       	if(i< count-1 )	     
	       	  	file  << ", ";

  	}
  }

  file<<endl;
  file.close();
}


void Faculty::removeAdvisee(int studentID)
{
	/*cout<<"ADVISEES BEFORE:";
	for(int i=0;i<5;++i)
  	{
  		cout << adviseesID[i];
	    if(i < maxSize) 
	       cout  << ", ";
  	}*/

	for(int i = 0; i < 5;++i)
	{
		if(adviseesID[i] == studentID)
		{
			adviseesID[i] = -1;
			--numAdvisees;
		}
	}

	/*cout<<"ADVISEES AFTER:";
	for(int i=0;i<5;++i)
  	{
  		cout << adviseesID[i];
	    if(i < maxSize) 
	       cout  << ", ";
  	}*/
}





