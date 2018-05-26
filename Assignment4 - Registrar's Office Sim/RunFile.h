#include <string>
#include "Customer.h"
#include "GenQueue.h"

using namespace std;

class RunFile
{
	public:
		RunFile();
		~RunFile();

		void read(string inFile);
		void simulation();

		int numberOfOpenWindows;
		int numberOfStudents;
		int timeOfService;
		int clockTick;

		//statistics variables
		int numberCustomers;
		int totalNumberOfCustomers;
		int *customerWaitTime;
		int longestCustomerWaitTime;
		int totalWaitTime;
		int *serviceWindowIdleTime;
		int totalWindowIdleTime;
		int longestWindowIdleTime;

		//statistics function
		double showMedian(int *array, int size);

		//Customer* *serviceWindow; //pointing whats at in the linked list 
		int *serviceWindows;
		int *idleTime;

		//creating queue of type customer
		GenQueue<Customer> *testQueue = new GenQueue<Customer>();

		//statistics to calculate
		//1 Mean student wait time
		//2 Median student wait time
		//3 Longest student wait time
		//4 Number of students waiting over 10 minutes
		//5 Mean window idle time
		//6 Longest window idle time
		//7 Number of windows idle for over 5 minutes

};