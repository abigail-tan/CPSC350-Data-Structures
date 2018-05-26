#include <iostream>

using namespace std;

template <class T>
class List
{
	public:	
		virtual void insertFront(T* d)=0;
		virtual void insertBack(T* d)=0;
		virtual T* removeFront()=0;
		virtual T* removeBack()=0;
		virtual T* peekFront()=0;
		virtual T* peekBack()=0;
		virtual T* printList()=0;
		virtual unsigned int getSize()=0;
		virtual bool isEmpty()=0;
};