#include <iostream>

class Customer
{
public:
	Customer();
	~Customer();

	void BuildCustomer( int inTimeInLine, int inTimeService );

	int timeInLine;			// time customer entered queue
	int timeService;		// length of time needed for service
	int timeWaiting;		// time waiting for service
};