#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
using namespace std; 
class Student
{
public:
	Student(); 
	~Student(); 


	int getId();
	string getName();
	string getLevel(); 
	string getMajor(); 
	double getGpa(); 

	int getAdvisor();

	void setAdvisor(int advisorId_);
	Student(int id_); 
	Student(int id_, string name_, string level_, string major_, double gpa_, int aid);
	void clearFile(); 

	void callKeyConst(const Student &stud);
	friend bool operator> (const Student &s1, const Student &s2);
	friend bool operator< (const Student &s1, const Student &s2);
	friend bool operator<= (const Student &s1, const Student &s2);
	friend bool operator>= (const Student &s1, const Student &s2);
	friend bool operator!= (const Student &s1, const Student &s2);
	friend bool operator== (const Student &s1, const Student &s2);
	friend ostream& operator<<(ostream& os, const Student &stud); 


	void printStudent(); 
	void writeStudent();

	void searchGpa(double g);
	void noStudents();
	//private:
	int id; 
	string name; 
	string level; 
	string major; 
	double gpa; 
	int advisorId; 	
	int count = 0;
};