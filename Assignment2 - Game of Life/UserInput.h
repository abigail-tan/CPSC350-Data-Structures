
#include <iostream>

using namespace std; 

class UserInput{
	public:
		UserInput();
		~UserInput();

		int getFileType();
		void readFile(string filePath);
		int gameMode();
		int getOutputMethod();

		string validFilePath();
		int validIntInput(int x);
		double validDoubleInput(double x);

		string getFilePath();
		int getHeight();
		int getWidth();
		double getDensity();


	private:
		int fileType; 
		string filePath; 

		int height;
		int width; 
		double density;
};