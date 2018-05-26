#include "ListNode.h"
#include "List.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList : public List<T>
{
	private: 
		ListNode<T> *front; //pointer to front of list
		ListNode<T> *back;  //pointer to back of list
		unsigned int size;  //unsigned to make size never be negative

	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		//inserts T* at the front of the list
		virtual void insertFront(T* d);
		
		//inserts T* at the back of the list 
		virtual void insertBack(T* d);

		//return T* and remove from the front of the list 
		virtual T* removeFront();

		//return T* and remove from the back of the list
		virtual T* removeBack();

		//returns T* and views front of the list
		virtual T* peekFront();

		//returns T* and views back of the list
		virtual T* peekBack();

		//print out the list
		virtual T* printList();

		virtual unsigned int getSize();

		virtual bool isEmpty(); //true if list is empty 
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	size = 0;
	front = NULL;
	back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (front->next == NULL)
	{
		delete front;
		delete back;
	}
	else 
	{
		ListNode<T> *temp = front;
		while (front->next != NULL)
		{
			temp = front->next;
			front->next = NULL;
			temp->prev = NULL;
			delete front;
			front = temp;
		}
	}
}

template <class T>
void DoublyLinkedList<T>::insertFront(T* d)
{
	ListNode<T> *node = new ListNode<T>(d);

	//need to make check to see if its null...

	if (size == 0)
	{
		back = node;
	}
	else 
	{
		front->prev = node; 
		node->next = front;
	}
	front = node;
	size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T* d)
{
	ListNode<T> *node = new ListNode<T>(d);

	if (size == 0)
	{
		front = node;
	}
	else 
	{
		back->next = node;
		node->prev = back;
	}
	back = node;
	++size; 
}

template <class T> 
T* DoublyLinkedList<T>::removeFront()
{
	ListNode<T> *temp = front;

	if(front->next == NULL) //checks if only one element in the list
	{
		back = NULL;
	}
	else //more than one element in link list
	{
		front->next->prev = NULL; 
	}
	front = front->next; 
	--size;
	temp->next = NULL;
	T* val = temp->data;
	
	delete temp;
	return val;
}

template <class T>
T* DoublyLinkedList<T>::removeBack()
{
	ListNode<T> *temp = back;

	if (back->prev == NULL)
	{
		front = NULL;
	}
	else 
	{
		back->prev->next = NULL;
	}
	back = back->prev;
	--size;
	temp->prev = NULL;
	T* val = temp->data;

	delete temp;
	return val;
}

template <class T>
T* DoublyLinkedList<T>::peekFront()
{
	return front->data;
}

template <class T>
T* DoublyLinkedList<T>::peekBack()
{
	return back->data;
}

template <class T>
T* DoublyLinkedList<T>::printList()
{
	ListNode<T> *current = front;
	while( true )
	{
		if ( current == NULL )
			break;
		cout << current->data << endl;
		current = current->next;
	}
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
	return size;
}


template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
	return (size == 0);
}