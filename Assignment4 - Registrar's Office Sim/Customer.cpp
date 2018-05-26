#include <iostream>
#include "Customer.h"

using namespace std;

Customer::Customer()
{
	timeInLine = 0;			// time customer entered queue
	timeService = 0;		// length of time needed for service
	timeWaiting = 0;		// time waiting for service
}

Customer::~Customer(){}

void Customer::BuildCustomer( int inTimeInLine, int inTimeService )
{
	timeInLine = inTimeInLine;			// clock tick that customer entered the queue
	timeService = inTimeService;		// amount of time customer needs at the window
	timeWaiting = 0;					// initialize the amount of time customer is waiting for service
}