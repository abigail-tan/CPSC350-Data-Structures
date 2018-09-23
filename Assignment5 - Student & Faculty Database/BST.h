#include "TreeNode.h"
#include <iostream>
using namespace std; 
//change insert int to student to add
template <class T>
class BST
{
public:
	BST(); 
	~BST(); 

	void insert(T k); 
	T find(T k);
	bool contains(T k); 
	bool deleteNode(int k); 

	TreeNode<T> *getMin(); 
	TreeNode<T> *getMax(); 
	TreeNode<T> *getRoot(); 

	bool isEmpty(); 
	int getSize(); 

	void printNode(T k);
	void printTree(TreeNode<T> *node);
	void printTreeAll(); 

	void deleteAll(TreeNode<T> *node);

	TreeNode<T>* getSuccessor(TreeNode<T> *d);

private:
	TreeNode<T> *root;
	unsigned int size; 
}; 


template <class T>
BST<T>::BST()
{
	root = NULL; 
}

template <class T>
BST<T>::~BST()
{
	deleteAll(root);
 	//iterates and deletes
}

template <class T>
void BST<T>::deleteAll(TreeNode<T> *node)
{
	if(node==NULL)
	{
		//empty tree do nothing
	}
	else{
		if(node!=NULL)
		{
			if(node->left==NULL && node->right==NULL)
			{
				delete node;
				node = NULL; 
			}
			else{
				deleteAll(node->left); 
				deleteAll(node->right);
			}
		}
	}
}

template <class T>
void BST<T>::printNode(T k) {
	if (root == NULL) cout<<"Node not found."<<endl;
	else {
		TreeNode<T> *curr = root; // start at root
		while (curr->key != k) {
			if (k < curr->key) curr = curr->left;
			else curr = curr->right;
			if (curr == NULL) cout<<"Node not found."<<endl; // we didn't find it
		}
		cout<<curr->key;
	}
}

template <class T>
void BST<T>::printTree(TreeNode<T> *node)
{
	if(node==NULL)
	{
		return; 
	}

	else{
		printTree(node->left); 
		cout<<node->key<<endl;
		printTree(node->right); 
	}
}

template <class T>
void BST<T>::printTreeAll()
{
	printTree(root); 
}

template <class T>
TreeNode<T>* BST<T>::getMin()
{
	TreeNode<T> *curr = root; 
	if(root==NULL)
		return NULL;
	
	while(curr->left!=NULL)
	{
		curr = curr->left; 
	}

	return curr; 
}

template <class T>
TreeNode<T>* BST<T>::getMax()
{
	TreeNode<T> *curr = root; 
	if(root==NULL)
		return NULL; 

	while(curr->right != NULL)
	{
		curr = curr->right; 
	}

	return curr; 
}	

template <class T>
int BST<T>::getSize()
{
	return size;
}

template <class T>
TreeNode<T>* BST<T>::getRoot() 
{
    return root;
}

template <class T>
void BST<T>::insert(T k)
{
	size++; 
	TreeNode<T> *node = new TreeNode<T>(k); 
	if(root==NULL)
	{
		root = node; 
	}

	else{
		TreeNode<T> *curr = root; 
		TreeNode<T> *parent = NULL; 

		while(true)
		{
			parent = curr; 
			//go left
			if(k<curr->key)
			{
				curr = curr->left; 
				if(curr==NULL)
				{
					//found insertion point
					parent->left = node; 
					break; 
				}
			}

			//go right
			else{
				curr  = curr->right; 
				if(curr==NULL)
				{
					//insertion point
					parent->right = node; 
					break; 
				}
			}
		}
	}
}

template <class T>
bool BST<T>::contains(T k)
{
	if(root==NULL)
	{
		return false; 
	}

	else{
		TreeNode<T> *curr = root; 
		while(curr->key!=k)
		{
			if(k<curr->key)
			{
				curr = curr->left; 
			}

			else{
				curr = curr->right; 
			}

			if(curr==NULL)
			{
				return false; 
			}
		}
	}

	return true; 
}

template <class T>
T BST<T>::find(T k) 
{
    if (root == NULL) 
    	return T();
	else 
	{
		TreeNode<T> *curr = root; // start at root
		while (curr->key != k) 
		{
			if (k < curr->key) 
				curr = curr->left;
			else 
				curr = curr->right;
			if (curr == NULL) 
				return T(); // we didn't find it
		}
		return curr->key;
	}
}


template <class T>
bool BST<T>::deleteNode(int k)
{
	if(root==NULL)
	{
		return false; 
	}

	TreeNode<T> *current = root; 
	TreeNode<T> *parent = root; 
	bool isLeft = true; 

	while(current->key!=k)
	{
		parent = current; 
		if(k<current->key)
		{
			isLeft = true; 
			current = current->left; 
		}

		else{
			isLeft = false; 
			current = current->right;
		}

		if(current==NULL)
		{
			return false; 
		}
	}

	//no children
	if(current->left==NULL && current->right==NULL)
	{
		if(current==root)
		{
			root==NULL; 
		}

		else if(isLeft)
		{
			parent->left = NULL; 
		}

		else{
			parent->right = NULL; 
		}
	}

	//one child
	else if(current->right==NULL)
	{
		if(current==root)
		{
			root = current->left; 
		}

		else if(isLeft)
		{
			parent->left = current->left; 
		}

		else{
			parent->right = current->left; 
		}
	}

	else if(current->left==NULL)
	{
		if(current==root)
		{
			root = current->right; 
		}
		else if(isLeft)
		{
			parent->left = current->right;
		}
		else{
			parent->right = current->left; 
		}
	}

	//two children
	else{
		TreeNode<T> *successor = getSuccessor(current); 
		if(current==root)
		{
			root = successor; 
		}
		else if(isLeft)
		{
			parent->left = successor; 
		}
		else{
			parent->right = successor; 
		}
		successor->left = current->left; 
	}
	size--;
}

//establish who successor is, parent is
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d)
{
	TreeNode<T> *sp = d; 
	TreeNode<T> *successor = d; 
	TreeNode<T> *current = d->right; 
	while(current!=NULL)
	{
		sp = successor; 
		successor = current; 
		current = current->left; 
	}	

	if(successor!=d->right)
	{
		sp->left = successor->right; 
		successor->right = d->right; 
	}

	return successor; 
}
