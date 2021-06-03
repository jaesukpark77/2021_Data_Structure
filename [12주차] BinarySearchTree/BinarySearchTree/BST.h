#pragma once
#include "BinaryTree.h"
using namespace std;

template < class btElementType >
class BST : public BinaryTree < btElementType > {
public:
	BST();
	virtual void insert(const btElementType& d);
	// Precondition: if d is a left child, then d must be < parent->getData();
	//    if d is a right child, then d must be > parent->getData();
	// Postconditions: T->retrieve(k)->getData() == d

	virtual BinaryTree < btElementType >* retrieve(const btElementType& d);
	// Precondition: none
	// Postcondition: none
	// Returns: if T contains a node matching d, then
	//    T->retrieve(d)->getData() == d; otherwise, T->isEmpty()
};

template < class btElementType >
void
BST < btElementType >
::insert(const btElementType& d)
{
	if (this->nullTree) {
		this->nullTree = false;
		this->leftTree = new BST;
		this->rightTree = new BST;
		this->treeData = d;
	}
	else if (d == this->treeData)
		this->treeData = d;
	else if (d < this->treeData)
		this->leftTree->insert(d);
	else
		this->rightTree->insert(d);
}

template < class btElementType >
BinaryTree < btElementType >*
BST < btElementType >
::retrieve(const btElementType& d)
{
	if (this->nullTree || d == this->treeData)
		return this;
	else if (d < this->treeData)
		return ((BST <btElementType> *)this->leftTree)->retrieve(d);
	else
		return ((BST <btElementType> *)this->rightTree)->retrieve(d);
}

template < class btElementType >
BST < btElementType >
::BST() : BinaryTree < btElementType >()
{

}