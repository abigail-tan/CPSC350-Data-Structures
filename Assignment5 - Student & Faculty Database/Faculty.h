#include <iostream>
#include <ostream>
#include <string>
using namespace std; 

class Faculty
{
public:
	Faculty(); 
	~Faculty();
	Faculty(int id_); 
	Faculty(int id_, string name_, string level_, string dept_);
	int *adviseesID; 
	int maxSize;  
	int numAdvisees; 
	void clearFile(); 
	void printAdvisees(); 
	void printFacultyMember(); 
	void writeFacultyMember(); 
	void removeAdvisee(int studentID);
	int countAdvisees(); 
	void increaseAdvisees();

	friend bool operator> (const Faculty &f1, const Faculty &f2);
	friend bool operator< (const Faculty &f1, const Faculty &f2);
	friend bool operator>= (const Faculty &f1, const Faculty &f2);
	friend bool operator<= (const Faculty &f1, const Faculty &f2);
	friend bool operator== (const Faculty &f1, const Faculty &f2);
	friend bool operator!= (const Faculty &f1, const Faculty &f2);
	friend ostream& operator<<(ostream& os, const Faculty &faculty); 

	int id; 
	string name; 
	string level; 
	string dept;

	//doubly linked list 

};