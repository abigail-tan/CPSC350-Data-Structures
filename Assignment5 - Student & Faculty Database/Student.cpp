#include <iostream>
#include<ostream>
#include <fstream>
#include "Student.h"
using namespace std; 

Student::Student()
{

}

Student::~Student()
{

}

Student::Student(int id_, string name_, string level_, string major_, double gpa_ ,int aid)
{
	id = id_; 
	name = name_; 
	level = level_; 
	major = major_; 
	gpa = gpa_; 
	advisorId = aid; 
}

int Student::getId()
{
	return id; 
}

string Student::getName()
{
	return name; 
}

string Student::getLevel()
{
	return level; 
}

string Student:: getMajor()
{
	return major; 
}

double Student::getGpa()
{
	return gpa; 
}

int Student::getAdvisor()
{
	return advisorId; 
}

Student::Student(int id_)
{
	id = id_;
	name = "";
	level = "";
	major = "";
	gpa = -1.0;
	advisorId = -1;
}

void Student::clearFile()
{
	ofstream file; 
	file.open("studentTable.txt");
	file.clear(); 
	file.close(); 
}

ostream& operator<<(ostream& os, const Student &stud)
{
	os<<stud.id; 
	return os; 
}

void Student::callKeyConst(const Student &stud)
{
	int k = stud.id; 
}

bool operator> (const Student &s1, const Student &s2)
{
	return (s1.id > s2.id); 
}

bool operator< (const Student &s1, const Student &s2)
{
	return s1.id < s2.id; 
}

bool operator<= (const Student &s1, const Student &s2)
{
	return s1.id <= s2.id; 
}

bool operator>= (const Student &s1, const Student &s2)
{
	return s1.id >= s2.id; 
}

bool operator!= (const Student &s1, const Student &s2)
{
	return (s1.id!=s2.id);
}

bool operator== (const Student &s1, const Student &s2)
{
	return (s1.id==s2.id);
}

void Student::setAdvisor(int advisorId_) {
  advisorId = advisorId_;
}

void Student::printStudent()
{
	cout << "ID: " << id << " | ";
  cout << "Name: " << name << " | ";
  cout << "Grade: " << level << " | ";
  cout << "Major: " << major << " | ";
  cout << "GPA: " << gpa << " | ";
  cout << "Advisor ID: " << advisorId << endl;
}

void Student::writeStudent()
{
	ofstream fileStudent; 
	fileStudent.open("studentTable.txt",std::ios_base::app); 
	fileStudent << id << "|";
  	fileStudent<<name << "|";
	fileStudent <<level << "|";
 	fileStudent << major << "|";
  	fileStudent  <<gpa << "|";
  	fileStudent << advisorId << endl;

  	fileStudent.close(); 
}

void Student::searchGpa(double g)
{
	if(gpa>=g)
	{
	  count++;
	  cout << "ID: " << id << " | ";
	  cout << "Name: " << name << " | ";
	  cout << "Grade: " << level << " | ";
	  cout << "Major: " << major << " | ";
	  cout << "GPA: " << gpa << " | ";
	  cout << "Advisor ID: " << advisorId << endl;
	}
}

void Student::noStudents()
{
	if(count == 0)
		cout<<"There are no students with a GPA equal to or higher than "<<gpa<<endl;
}