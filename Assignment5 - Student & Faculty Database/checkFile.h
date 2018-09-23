using namespace std;
class checkFile
{
public:
	checkFile();
	checkFile(string name);
	~checkFile(); 
	bool fileExists(string name);
	string fileName;	
};