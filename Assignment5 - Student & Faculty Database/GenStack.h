#include <iostream>

using namespace std;

template<class T>
class GenStack {
	private:
		T *myArray;
		T *tempArray;

		int max;
		int top;

	public:
		GenStack(int maxSize);
		~GenStack();

		void push(int data);
		T* pop();
		T* peek();

		int getSize();
		int isEmpty();
		int isFull();

		void expand();
};

template<class T>
GenStack<T>::GenStack(int maxSize)
{
	myArray = new T[maxSize];
	max = maxSize;
	top = -1;

	tempArray = new T[max];
}

template<class T>
GenStack<T>::~GenStack()
{
	delete []myArray;
	delete []tempArray;

	cout << "Objects Destroyed" << endl;
}

template<class T>
void GenStack<T>::push(int data)
{
	if(isFull() == 1)
	{
		expand();
		push(data);
	}
	else
	{
		myArray[++top] = data;
	}
}

template<class T>
T* GenStack<T>::pop()
{
	if(isEmpty() == 1)
	{
		cout << "Stack is Empty" << endl;
	}
	else
	{
		return myArray[top--];
	}
}

template<class T>
T* GenStack<T>::peek()	//checks a value at a specific point
{
	if(top == -1)
	{
		//
	}
	else
	{
		return myArray[top];
	}
}

template<class T>
int GenStack<T>::getSize()
{
	return (top + 1);
}

template<class T>
int GenStack<T>::isEmpty()
{
	return(top == -1);
}

template<class T>
int GenStack<T>::isFull()
{
	return(top == (max - 1));
}

template<class T>
void GenStack<T>::expand()
{
	tempArray = new T[max];

	for(int i = top; i > -1; --i) //copies all to temp array
	{
		tempArray[i] = myArray[i];
	}

	max += 10;	//adds 10 spaces
	myArray = new T[max];

	for(int i = top; i > -1; --i) //copies again and puts them in the new bigger array
	{
		myArray[i] = tempArray[i];
	}
}
