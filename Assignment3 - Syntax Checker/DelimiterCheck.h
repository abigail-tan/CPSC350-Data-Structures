#include <iostream> 

using namespace std; 

class DelimiterCheck{
	public:
		DelimiterCheck(); //constructor
		~DelimiterCheck(); //destructor

		string checkFile(string file);
		int checkSyntax(string file);
};