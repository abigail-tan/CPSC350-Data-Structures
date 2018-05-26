#include <iostream> 
#include <stack>
#include <string>

using namespace std; 

template <class T>
class GenStack
{
	public: 
		GenStack(); //constructor
		GenStack(int maxSize); //overloaded constructor
		~GenStack(); //destructor

		void push(T d);
		T pop();
		T peek(); 

		bool isFull(); 
		bool isEmpty();
		void increaseSize(); 

		int size; 
		int top; 

		T *myArray;
		T *tempArray; 
};

//constructor
template <class T>
GenStack<T>::GenStack()
{ 

}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize)
{ 
	myArray = new char[maxSize];
	size = maxSize;
	top = -1;
	tempArray = new T[size]; 
}

//destructor
template <class T>
GenStack<T>::~GenStack()
{
	delete []myArray;
	delete []tempArray;
}


template <class T>
void GenStack<T>::push(T data)
{
	//if full, can't do anything--need to increase size of array
	if(isFull())
	{
		increaseSize();
		myArray[++top] = data; 
	}

	myArray[++top] = data; 
}

template <class T>
T GenStack<T>::pop()
{ 
	//if empty, can't do anything
	if(isEmpty()){
		cout<<"Error: the current stack is empty.\n";
		return 0;
	}
	return myArray[top--];
}

template <class T>
T GenStack<T>::peek()
{
	//if empty, there's nothing to look at
	if(isEmpty()){
		cout<<"Error: the current stack is empty.\n";
		return 0;
	}
	return myArray[top];
}

template <class T>
bool GenStack<T>::isFull()
{
	return (size-1  == top);
}

template <class T>
bool GenStack<T>::isEmpty()
{
	return (top == -1);
}

template <class T>
void GenStack<T>::increaseSize()
{	
	//puts what's in the array into another array but reverse
	for (int i = top; i > -1; --i) {
        tempArray[i] = myArray[i];
	}

	//increases stack size by one
	size += 1;
    myArray = new T[size];

    //puts everything back into the increased stack in the right order
    for (int i = top; i > -1; --i) {
        myArray[i] = tempArray[i];
	}
}

