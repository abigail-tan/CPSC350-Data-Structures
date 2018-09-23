#include <iostream>
#include "BST.h"
using namespace std; 
class Simulation
{
public:

	Simulation(); 
	~Simulation(); 

	void readFaculty(); 
	void readStudent(); 
	BST<Faculty> masterFaculty; 
	BST<Student> masterStudent;

	void printMenu();
	void userChoice();
	bool isValidInt(string temp);
	void printAllStudents();
	void printMS(TreeNode<Student> *s);
	void printAllFaculty(); 
	void printMF(TreeNode<Faculty> *f);
	void printStudent();
	void printFacultyMember();
	void printAdvisor();
	void printAdvisees();
	void addStudent(); 
	void addFaculty();
	int generateID(int max, int min); 
	bool IDTakenStudent(Student s);
	bool IDTakenFaculty(Faculty f);
	void addFacultyMember(Faculty f);
	void deleteStudent();
	void deleteFacultyMember();
	void changeAdvisor();
	void removeAdvisee();
	void searchByGPA();
	void searchGpaStudent(TreeNode<Student> *s,double gpa);
	void rollback();
	void exit();
	void writeFileStudent(TreeNode<Student> *s);
	void writeFileFaculty(TreeNode<Faculty> *f);
};