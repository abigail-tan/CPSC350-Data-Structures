#include <iostream>
#include <fstream>
#include <string>
//#include "BST.h"
#include <cstdlib>
#include "Student.h"
#include "Faculty.h"
#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
	readFaculty(); 
	readStudent(); 
	userChoice();
}

Simulation::~Simulation()
{

}

void Simulation::readFaculty()
{
	//Faculty facultyMem; 
	ifstream infile("facultyTable.txt"); 
	if(infile.is_open()&&infile.good())
	{
		string lines;
		while(!getline(infile,lines,'|').eof())
		{
				Faculty facultyMem; 

			facultyMem.id = atoi(lines.c_str());
			getline(infile,facultyMem.name,'|');
			getline(infile,facultyMem.level,'|');
			getline(infile,facultyMem.dept,'|'); 
			string idsCount;
			getline(infile,idsCount,'|'); 
			int idTmp = atoi(idsCount.c_str()); 
			string id2; 
			
			for(int i=0; i<idTmp;i++)
			{
				if(i==idTmp-1)
				{
					string idSep; 
					getline(infile,idSep); 
					int temp = atoi(idSep.c_str()); 
					facultyMem.adviseesID[i]=temp;  
					//cout<<"id:"<<facultyMem.adviseesID[i]<<endl;
					facultyMem.numAdvisees++;
				}
				else
				{
					string idSep; 
					getline(infile,idSep,','); 
					int temp = atoi(idSep.c_str()); 
					facultyMem.adviseesID[i]=temp;  
					//cout<<"id:"<<facultyMem.adviseesID[i]<<endl;
					facultyMem.numAdvisees++;
				}

			}
			masterFaculty.insert(facultyMem); 
			facultyMem.numAdvisees=0;
		}

	}

	infile.close();
	Faculty faculty;
	faculty.clearFile(); 
}

void Simulation::readStudent()
{
	Student studMem; 
	ifstream infile("studentTable.txt"); 
	if(infile.is_open()&&infile.good())
	{
		string lines; 
		while(!getline(infile,lines,'|').eof())
		{
			studMem.id = atoi(lines.c_str()); 
			getline(infile,studMem.name,'|'); 
			getline(infile,studMem.level,'|'); 
			getline(infile,studMem.major,'|'); 
			string gpaTmp; 
			getline(infile,gpaTmp,'|'); 
			studMem.gpa = atof(gpaTmp.c_str()); 
			string idTemp; 
			getline(infile,idTemp); 
			studMem.advisorId = atoi(idTemp.c_str()); 

			masterStudent.insert(studMem); 
		}
	}

	infile.close();
	Student stud; 
	stud.clearFile(); 
	//masterStudent.printTreeAll();
}


void Simulation::printMenu()
{
	cout<<"\nMENU\n";
	cout<<"1. Print all student info by ascending ID."<<endl;
	cout<<"2. Print all faculty info by ascending ID."<<endl;
	cout<<"3. Print student info by student ID number."<<endl;
	cout<<"4. Print faculty info by faculty ID number."<<endl;
	cout<<"5. Print info of a student's faculty advisor."<<endl;
	cout<<"6. Print all the advisees of a faculty member."<<endl;
	cout<<"7. Add a new student."<<endl;
	cout<<"8. Delete a student."<<endl;
	cout<<"9. Add a new faculty member."<<endl;
	cout<<"10. Delete a faculty member."<<endl;
	cout<<"11. Change a student's advisor."<<endl;
	cout<<"12. Remove an advisee from a faculty member."<<endl;
	cout<<"13. Search for students by GPA range."<<endl;
	cout<<"14. Rollback."<<endl;
	cout<<"15. Exit."<<endl<<endl;
}

void Simulation::userChoice()
{
	string userInput;
	int choice = 0;
	while(true)
	{	
		printMenu();
		cout<<"Enter an option: ";
		cin >> userInput;
		while(!isValidInt(userInput))
		{
			cout<<"Not a valid response. Try again."<<endl;
			cin.clear();		
			cin.ignore(10000,'\n');
			cout<<"Enter a valid int: ";
			cin>>userInput;
			cout<<endl;
		}
		choice = atoi(userInput.c_str());
		switch(choice)
		{
			case 1:
				printAllStudents();
				break;
			case 2:
				printAllFaculty();
				break;
			case 3:
				printStudent();
				break;
			case 4:
				printFacultyMember();
				break;
			case 5:
				printAdvisor();
				break;
			case 6:
				printAdvisees();
				break;
			case 7:
				addStudent();
				break;
			case 8:
				deleteStudent();
				break;
			case 9:
				addFaculty();
				break;
			case 10:
				deleteFacultyMember();
				break;
			case 11:
				changeAdvisor();
				break;
			case 12:
				removeAdvisee();
				break;
			case 13:
				searchByGPA();
				break;
			case 14:
				rollback();
				break;
			case 15:
				exit();
				return;
			default:
				cout<<"Invalid option. Try again.\n";
				continue;
		}
	}
}

bool Simulation::isValidInt(string temp)
{
	for (int i=0; i<temp.size(); ++i) 
	{
		if (!isdigit(temp[i])) 
		{
			if(temp[i] == '.')
			{
				continue;
			}
			return false;
			break;
		}
		else
			return true;
	}
}

void Simulation::printAllStudents()
{
	if(masterStudent.getRoot() == NULL)
	{
		cout<<"\nStudent data base is empty."<<endl;
	}
	else
	{
		printMS(masterStudent.getRoot());
	}
}

void Simulation::printMS(TreeNode<Student> *s)
{
	if(s != NULL)
	{
		if(s->left != NULL)
		{
			printMS(s->left);
		}
		(s->key).printStudent();

		if(s->right != NULL)
		{
			printMS(s->right);
		}
	}
	else
	{
		cout<<"Student database is empty."<<endl;
	}
}


void Simulation::printAllFaculty()
{
	if(masterFaculty.getRoot() == NULL)
	{
		cout<<"\nFaculty data base is empty."<<endl;
	}
	else
	{
		printMF(masterFaculty.getRoot());
	}
}

void Simulation::printMF(TreeNode<Faculty> *f)
{
	if(f != NULL)
	{
		if(f->left != NULL)
		{
			printMF(f->left);
		}
		(f->key).printFacultyMember();

		if(f->right != NULL)
		{
			printMF(f->right);
		}
	}
	else
	{
		cout<<"Faculty database is empty."<<endl;
	}
}

void Simulation::printStudent()
{
	cout<<"\nStudent IDs in database: "<<endl;
	masterStudent.printTreeAll();
	cout<<endl;

	int id = 0;
	string possibleId;
	cout<<"Enter the student ID number: ";
	cin>>possibleId;
	while(!isValidInt(possibleId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleId;
	}
	id = atoi(possibleId.c_str());
	Student temp(id);
	Student student = masterStudent.find(temp);
	if(masterStudent.contains(student))
		masterStudent.find(student).printStudent();
	else
		cout<<"Student record doesn't exist.\n";
}

void Simulation::printFacultyMember()
{
	cout<<"\nFaculty IDs in database: "<<endl;
	masterFaculty.printTreeAll();
	cout<<endl;

	int id = 0;
	string possibleId;
	cout<<"Enter the faculty member ID number: ";
	cin>>possibleId;
	while(!isValidInt(possibleId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleId;
	}
	id = atoi(possibleId.c_str());
	Faculty temp(id);
	Faculty facultyMem = masterFaculty.find(temp);
	if(masterFaculty.contains(facultyMem)){
		masterFaculty.find(facultyMem).printFacultyMember();
	//	masterFaculty.find(facultyMem).printAdvisees();
	}
	else
		cout<<"Faculty member record doesn't exist.\n";
}

void Simulation::printAdvisor()
{
	cout<<"\nStudent IDs in database: "<<endl;
	masterStudent.printTreeAll();
	cout<<endl;

	int facultyId;
	int studentId;
	string possibleStuId;
	cout<<"Enter the student ID number: ";
	cin>>possibleStuId;
	while(!isValidInt(possibleStuId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleStuId;
	}
	studentId = atoi(possibleStuId.c_str());
	Student temp(studentId);
	Student student = masterStudent.find(temp);
	if(masterStudent.contains(student))
	{
		facultyId = masterStudent.find(student).getAdvisor();
		Faculty temp(facultyId);
		Faculty facultyMem = masterFaculty.find(temp);
		masterFaculty.find(facultyMem).printFacultyMember();
	}	
	else
		cout<<"Student record doesn't exist.\n";
}

void Simulation::printAdvisees()
{
	cout<<"\nFaculty IDs in database: "<<endl;
	masterFaculty.printTreeAll();
	cout<<endl;

	int id;
	string possibleId;
	cout<<"Enter the faculty member ID number: ";
	cin>>possibleId;
	while(!isValidInt(possibleId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleId;
	}
	id = atoi(possibleId.c_str());	Faculty temp(id);
	Faculty facultyMem = masterFaculty.find(temp);
	if(masterFaculty.contains(facultyMem))
		masterFaculty.find(facultyMem).printAdvisees();
	else
		cout<<"Faculty member record doesn't exist.\n";

  	cout << endl;
}

int Simulation::generateID(int max, int min)
{
	int randNum = rand()%(max-min + 1) + min;
	return randNum; 
}


void Simulation::addStudent()
{
	//generate student id
	//check if all entires are good 
	Student studMem; 
	srand(time(0));

	string possibleGpa;
	string possibleFacId;

	studMem.id = generateID(10000,5000);
	if(IDTakenStudent(studMem))
		studMem.id = generateID(10000,5000);
	cout<<"NEW STUDENT'S GENERATED ID NUMBER: "<<studMem.id<<endl;
	cout<<"NAME:"<<endl; 
	cin.ignore();
	getline(cin,studMem.name);
	cout<<"LEVEL:"<<endl;
	getline(cin,studMem.level); 
	cout<<"MAJOR:"<<endl;
	getline(cin,studMem.major);
	cout<<"GPA:"<<endl;
	cin>>possibleGpa;
	while(!isValidInt(possibleGpa))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid double: ";
		cin>>possibleGpa;
	}
	studMem.gpa = atoi(possibleGpa.c_str());

	cout<<"\nFaculty IDs to Choose From: "<<endl;
	masterFaculty.printTreeAll();
	cout<<endl;

	cout<<"ADVISOR ID:"<<endl; 
	cin>>possibleFacId;
	while(!isValidInt(possibleFacId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleFacId;
	}
	studMem.advisorId = atoi(possibleFacId.c_str());
	
	masterStudent.insert(studMem);

	Faculty temp(studMem.advisorId);
	Faculty facultyMem = masterFaculty.find(temp);
	if(masterFaculty.contains(facultyMem))
	{
		int count=0; 
		
		for(int i=0; i<5;i++)
		{

			if(masterFaculty.find(facultyMem).adviseesID[i]==-1)
			{
				count++; 
				
				if(count<=1)
				{
					masterFaculty.find(facultyMem).adviseesID[i]=studMem.id;
					facultyMem.numAdvisees++; 
					//masterFaculty.find(facultyMem).increaseAdvisees(); 

				}
			}
			else if(i==4)
			{
				cout<<"This advisor can't advise more students"<<endl;
			}

		}
	}
	
	else{
		cout<<"Faculty member doesn't exist.\n";
		//randomly assign
	}

	cout<<endl<<"STUDENT ADDED:"<<endl;
	masterStudent.find(studMem).printStudent();
}


bool Simulation::IDTakenStudent(Student s)
{
	bool taken = false; 
	if(masterStudent.contains(s))
	{
		taken = true;
	}
	return taken; 
}

bool Simulation::IDTakenFaculty(Faculty f)
{
	bool taken = false; 
	if(masterFaculty.contains(f))
		taken = true;
	return taken; 
}

void Simulation::addFaculty()
{
	Faculty facultyMem; 
	srand(time(0));

	facultyMem.id = generateID(5000,1000);
	if(IDTakenFaculty(facultyMem))
		facultyMem.id = generateID(5000,1000);
	cin.ignore();
	cout<<"NEW FACULTY MEMBER'S GENERATED ID NUMBER: "<<facultyMem.id<<endl;
	cout<<"NAME:"<<endl;
	getline(cin, facultyMem.name);
	
	cout<<"LEVEL:"<<endl;
	getline(cin,facultyMem.level); 
	
	cout<<"DEPARTMENT:"<<endl;
	getline(cin,facultyMem.dept); 
	
	masterFaculty.insert(facultyMem); 
	cout<<endl<<"FACULTY ADDED:"<<endl;
	masterFaculty.find(facultyMem).printFacultyMember(); 
}

void Simulation::addFacultyMember(Faculty f)
{
	masterFaculty.insert(f); 
}

void Simulation::deleteStudent()
{
	cout<<"\nStudent IDs in database: "<<endl;
	masterStudent.printTreeAll();

	string possibleId;
	int studentId;
	cout<<"\nPlease enter the student ID you could like to delete: ";
	cin>> possibleId;
	while(!isValidInt(possibleId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleId;
	}
	studentId = atoi(possibleId.c_str());
	Student temp(studentId);
	if(masterStudent.contains(temp))
	{
		masterFaculty.find(masterStudent.find(temp).getAdvisor()).removeAdvisee(studentId);
		masterStudent.deleteNode(studentId);
	}
	else
		cout<<"Student record doesn't exist.\n";
}

void Simulation::deleteFacultyMember()
{
	cout<<"\nFaculty IDs in database: "<<endl;
	masterFaculty.printTreeAll();

	string possibleId;
	int facultyId;
	cout<<"\nPlease enter the faculty member ID you would like to delete: ";
	cin>> possibleId;
	while(!isValidInt(possibleId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleId;
	}
	facultyId = atoi(possibleId.c_str());
	if(masterFaculty.contains(facultyId))
	{
		for(int i = 0; i<masterFaculty.find(facultyId).maxSize;++i)
		{

			if(masterFaculty.find(facultyId).adviseesID[i] != -1)
			{
				Student temp(masterFaculty.find(facultyId).adviseesID[i]);
				Student student = masterStudent.find(temp);
				
				int newId = student.getId();
				string newName = student.getName();
				string newLevel = student.getLevel();
				string newMajor = student.getMajor();
				double newGpa = student.getGpa();

				masterStudent.deleteNode(masterFaculty.find(facultyId).adviseesID[i]);
				Student newStudent(newId, newName, newLevel, newMajor, newGpa, -1);
				masterStudent.insert(newStudent);
			}
		}
	}
	masterFaculty.deleteNode(facultyId);
}

void Simulation::changeAdvisor()
{	
	cout<<"\nStudent IDs in database: "<<endl;
	masterStudent.printTreeAll();
	cout<<"\nFaculty IDs in database: "<<endl;
	masterFaculty.printTreeAll();

	string possibleStuId;
	string possibleFacId;
	int facultyId;
	int facultyIdNew; 
	int studentId;
	cout<<endl<<"Enter the student ID:"<<endl;
	cin>>possibleStuId;
	while(!isValidInt(possibleStuId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleStuId;
	}
	studentId = atoi(possibleStuId.c_str());

	cout<<endl; 

	cout<<"Enter the new Advisor ID:"<<endl;
	cin>>possibleFacId;  
	while(!isValidInt(possibleFacId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleFacId;
	}
	facultyIdNew = atoi(possibleFacId.c_str());

	Student temp(studentId);
	Student student = masterStudent.find(temp);
	if(masterStudent.contains(student))
	{
		facultyId = masterStudent.find(student).getAdvisor();
		Faculty temp(facultyId);
		Faculty facultyMem = masterFaculty.find(temp);
		masterFaculty.find(facultyMem).removeAdvisee(studentId);

		Faculty tempNew(facultyIdNew);
		Faculty facultyMemNew = masterFaculty.find(tempNew); 

		int newId = student.getId();
		string newName = student.getName();
		string newLevel = student.getLevel();
		string newMajor = student.getMajor();
		double newGpa = student.getGpa();

		int newAdvisorId = facultyIdNew;
		masterStudent.deleteNode(studentId);
		Student newStudent(newId, newName, newLevel, newMajor, newGpa, newAdvisorId);
		masterStudent.insert(newStudent);

		Faculty tempNew2(newStudent.advisorId);
		Faculty facultyMem2 = masterFaculty.find(tempNew2);
		if(masterFaculty.contains(facultyMem2))
		{
			int count=0; 
			
			for(int i=0; i<5;i++)
			{

				if(masterFaculty.find(facultyMem2).adviseesID[i]==-1)
				{
					count++; 
					
					if(count<=1)
					{
						masterFaculty.find(facultyMem2).adviseesID[i]=newStudent.id;
					}
				}
				else if(i==4)
				{
					cout<<"This advisor can't advise more students"<<endl;
				}

			}
		}
		
		else
		{
			cout<<"Faculty member doesn't exist.\n";
			//randomly assign
		}
	}	
	else
	{
		cout<<"Student record doesn't exist.\n";
	}

}

void Simulation::removeAdvisee()
{
	cout<<"\nStudent IDs in database: "<<endl;
	masterStudent.printTreeAll();

	string possibleId;
	int facultyId;
	int studentId;
	cout<<endl<<"Enter the student ID you would like to remove from an Advisor's list:"<<endl;
	cin>> possibleId;
	while(!isValidInt(possibleId))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid int: ";
		cin>>possibleId;
	}
	studentId = atoi(possibleId.c_str());
	Student temp(studentId);
	Student student = masterStudent.find(temp);
	
	if(masterStudent.contains(student))
	{
		//removes from faculty
		facultyId = masterStudent.find(student).getAdvisor();
		Faculty temp(facultyId);
		Faculty facultyMem = masterFaculty.find(temp);
		masterFaculty.find(facultyMem).removeAdvisee(studentId); 

		//removes faculty from student
		int newId = student.getId();
		string newName = student.getName();
		string newLevel = student.getLevel();
		string newMajor = student.getMajor();
		double newGpa = student.getGpa();

		masterStudent.deleteNode(studentId);
		Student newStudent(newId, newName, newLevel, newMajor, newGpa, -1);
		masterStudent.insert(newStudent);
	}	
	else
	{
		cout<<"Student record doesn't exist.\n";
	}
}

void Simulation::searchByGPA()
{
	double gpaMin;
	string possibleGpa;
	cout<<"Enter a minimum GPA: ";
	cin>>possibleGpa;
	while(!isValidInt(possibleGpa))
	{
		cout<<"Not a valid response. Try again."<<endl;
		cin.clear();		
		cin.ignore(10000,'\n');
		cout<<"Enter a valid double: ";
		cin>>possibleGpa;
	}
	gpaMin = atof(possibleGpa.c_str());
	searchGpaStudent(masterStudent.getRoot(),gpaMin);
}

void Simulation::searchGpaStudent(TreeNode<Student> *s,double gpa)
{
	if(s != NULL)
	{
		if(s->left != NULL)
		{
			searchGpaStudent(s->left,gpa);
		}
		(s->key).searchGpa(gpa);
		if(s->right != NULL)
		{
			searchGpaStudent(s->right,gpa);
		}
	}
	else
	{
		s->key.noStudents();
	}
}


void Simulation::rollback()
{
	//masterStudent = studentStack.pop()
	//masterFaculty = facultyStack.pop()
	cout<<"Rollback (Undo) is under maintenance. Sorry for the inconvenience!\n";	
}

void Simulation::exit()
{
	writeFileStudent(masterStudent.getRoot()); 
	writeFileFaculty(masterFaculty.getRoot());
	cout<<"Exiting..."<<endl;
}


void Simulation::writeFileStudent(TreeNode<Student> *s)
{
	if(s != NULL)
	{
		if(s->left != NULL)
		{
			writeFileStudent(s->left);
		}
		(s->key).writeStudent();

		if(s->right != NULL)
		{
			writeFileStudent(s->right);
		}
	}
}

void Simulation::writeFileFaculty(TreeNode<Faculty> *f)
{
	if(f != NULL)
	{
		if(f->left != NULL)
		{
			writeFileFaculty(f->left);
		}
		(f->key).writeFacultyMember();

		if(f->right != NULL)
		{
			writeFileFaculty(f->right);
		}
	}
}
