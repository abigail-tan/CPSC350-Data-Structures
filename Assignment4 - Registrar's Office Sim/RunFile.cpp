#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include "RunFile.h"
//#include "GenQueue.h"

using namespace std;

/*
	Read the input file and process it. The first line should be the number of service windows. The following lines should be formatted in
	the following manner... 
		clock tick
		number of customers
		(length of service time X number of customers)
	- Once the number of service windows is determined create the serviceWindow array of type Customer
	
	- Then proceed to read the remainder of the file using the algorithm above.
		+ get the clock tick
		+ get the number of students
		for loop to get length_of_service
		+ once a length of service is retrieved add entry to the queue of customers
*/

RunFile::RunFile()
{
	numberOfOpenWindows = 0;
	numberOfStudents = 0;
	timeOfService = 0;
	clockTick = 0;
}

RunFile::~RunFile(){}

void RunFile::read( string inFile )
{
	//GenQueue<Customer> *testQueue = new GenQueue<Customer>();
	totalNumberOfCustomers = 0;

	fstream simFile;
	string inLine;

	simFile.open(inFile.c_str());

	// number of windows
	getline( simFile, inLine );
	numberOfOpenWindows = stoi(inLine);
	cout << "Number of windows: " << numberOfOpenWindows << endl;

	// create array of windows
	/*serviceWindow = new Customer*[numberOfWindows];				// defined service window array and define limits
	for ( int i = 0; i < numberOfWindows; ++i )					// create the empty array
	{
		Customer* windowCustomer = new Customer();
		serviceWindow[ i ] = windowCustomer;
	}*/

	serviceWindows = new int[numberOfOpenWindows];				// defined service window array and define limits
	serviceWindowIdleTime = new int[numberOfOpenWindows];		// service window idle time array

	for ( int i = 1; i <= numberOfOpenWindows; ++i )					// create the empty array
	{
		serviceWindows[ i ] = 0;
	}

	// loop until eof
	while (getline( simFile, inLine ))
	{
		// get the clock tick
		clockTick = stoi(inLine);
		cout << "clock: " << clockTick << endl;

		// number of students at this arrival time
		getline( simFile, inLine );
		numberOfStudents = stoi( inLine );
		cout << "Students: " << numberOfStudents << endl;

		for ( int i = 0; i < numberOfStudents; ++i ) 
		{
			getline( simFile, inLine );
			timeOfService = stoi( inLine );
			cout << "Time of Service: " << timeOfService << endl;
			
			/* build virtual line but first create customer. */
			Customer* theCustomer = new Customer();
			theCustomer->BuildCustomer( clockTick, timeOfService );
			totalNumberOfCustomers++;
			cout<<"This is the specific customer's clock tick: " << theCustomer->timeInLine<<endl;
			cout<<"This is the specific customer's length of service: "<< theCustomer->timeService<<endl;
			cout<<"This is the specific customer's waiting time: "<< theCustomer->timeWaiting<<endl;

			//putting customers into queue
			testQueue->enqueue(theCustomer);
			cout<<testQueue->getSize()<<endl;
		}
	}

	cout << "total students in queue: " << totalNumberOfCustomers << endl;
	customerWaitTime = new int[totalNumberOfCustomers];
	for (int i = 0; i <= totalNumberOfCustomers; i++)
		{
			customerWaitTime[i] = 0;
		}
}

void RunFile::simulation()
{
	int clock = 0;
	bool finished = false; 
	int emptyWindows = numberOfOpenWindows;  // iniialize emptyWindows to be number of windows
	// initialize statistics variables
	numberCustomers = 0;
	totalWindowIdleTime = 0;
	longestWindowIdleTime = 0;

	while(finished != true)
	{
		//declaring the intial time
		cout<<"Clock Tick: "<<clock<<endl;

		if(!testQueue->isEmpty()) //checking whether queue of students is emptY
		{
			if(testQueue->peekFront()->timeInLine <= clock) // peek at customer at head to see timeInLine
			{
				if (emptyWindows > 0)		//NEED TO CHECK IF OPEN WINDOW
				{	
					for(int i = 1; i <= numberOfOpenWindows; ++i) //array of open windows
					{
						if(serviceWindows[i] == 0 && !testQueue->getSize() == 0 && testQueue->peekFront()->timeInLine <= clock)
						{
							Customer* temp1 = testQueue->dequeue();  
							serviceWindows[i] = temp1->timeService+1;
							// statistics for how long customer was waiting in line
							emptyWindows--;
							numberCustomers++;
							totalWaitTime += (clock - temp1->timeInLine);
							customerWaitTime[numberCustomers] = clock - temp1->timeInLine;
							cout << "Customer entered window number: " << i << endl;
							cout << "Customer wait time was: " << clock - temp1->timeInLine << endl;
							//cout << "Number of empty windows: " << emptyWindows << endl;
						}
						else 
						{
							cout << "No customers available for Window " << i << endl;
							continue;
						}
						cout<<"Window "<< i <<" occupied for: "<< serviceWindows[i] <<endl;
					}
				}
			}
			else
			{
				cout << "No customers at clock tick: " << clock << endl;
			}
		}

		// decrement window timers
		for(int i = 1; i <= numberOfOpenWindows; i++)
		{
			if(serviceWindows[i]!=0)
			{
				serviceWindows[i]--;
				cout << "Window " << i << " time remaining : " << serviceWindows[i] << endl;
				if (serviceWindows[i] == 0)
				{
					emptyWindows++;
					//statistics here
					cout << "emptyWindows = " << emptyWindows << endl;
				}				
			}
			else
			{
				//increment the serviceWindowIdleTime count serviceWindowIdleTime[i]
				serviceWindowIdleTime[i]++;
			}
		}

		// increment the clock
		clock++;	

		if(emptyWindows == numberOfOpenWindows && testQueue->isEmpty() == true)
		{
			finished = true;
			cout  << "Did I get here?\n";
			cout << "Time to calculate simulation statistics...\n";
			//cout<<"Empty Windows: "<<emptyWindows<<"\nOpen Windows: "<<numberOfOpenWindows<<endl;
			cout << "Number of customers served: " << numberCustomers << endl;
			//cout << "Total Wait Time: " << totalWaitTime << endl;
			cout << "Mean wait time: " << (float)totalWaitTime/(float)numberCustomers << endl;
			double medianCustomer = 0;
			medianCustomer = showMedian( customerWaitTime, totalNumberOfCustomers);
			cout << "Median customer wait time: " << medianCustomer << endl;
			for(int i = 1; i <= totalNumberOfCustomers; i++)
			{
				if ( longestCustomerWaitTime < customerWaitTime[i] )
					longestCustomerWaitTime = customerWaitTime[i];
				cout << i << " : " << customerWaitTime[i] << endl;
			}
			cout << "Longest customer wait time: " << longestCustomerWaitTime << endl;
			for(int i = 1; i <= numberOfOpenWindows; i++)
			{
				cout << "Window " << i << " idle time: " << serviceWindowIdleTime[i] << endl;
				totalWindowIdleTime += serviceWindowIdleTime[i];
				//cout << "total: " << totalWindowIdleTime << endl;;
				if (longestWindowIdleTime < serviceWindowIdleTime[i])
				{
					longestWindowIdleTime = serviceWindowIdleTime[i];
				}
			}
			cout << "Total window idle time: " << totalWindowIdleTime << endl;
			cout << "Mean window idle time: " << (float)totalWindowIdleTime / (float)numberOfOpenWindows << endl;
			cout << "Longest window idle time: " << longestWindowIdleTime << endl;
		}

		// just to catch runaways...
		//if (clock == 50)
		//	break;
	}
}

double RunFile::showMedian(int *array, int size)
{
    int middle = 0;
    double median = 0;
 
 	sort(array, array + size);

    middle = size / 2.0;
 
    if (size % 2)
    {
        median = (array[middle] + array[middle + 1]) / 2.0;
        cout << "The median is: " << median << endl;
    }
    else
    {
        median = array[middle + 0] / 1.0;
 
        cout << "The median is: " << median << endl;
    }
    return median;
}