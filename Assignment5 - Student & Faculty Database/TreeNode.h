#include <iostream>
using namespace std; 

template <class T>
class TreeNode
{
public:
	TreeNode(); 
	TreeNode(T k); 
	TreeNode(T* d,T k); 
	~TreeNode(); 

	T key; 
	TreeNode<T> *left; 
	TreeNode<T> *right;  
}; 

template <class T>
TreeNode<T>::TreeNode()
{
	key = 0; 
	left = NULL; 
	right = NULL; 
}

template <class T>
TreeNode<T>::TreeNode(T k)
{
	key = k; 
	left = NULL; 
	right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode()
{
	
}