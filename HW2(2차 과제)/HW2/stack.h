//전자정보공학부 IT융합과 20170586 박재석
#pragma once

#ifndef __MB_CX8_3__
#define __MB_CX8_3__

#include <assert.h>
const int maxStackSize = 1000;

template < class StackElementType >
class Stack
{
public:
	Stack();
	void push(StackElementType item);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();
	bool isFull();
private:
	StackElementType stackArray[maxStackSize];
	int topIndex;
};

template < class StackElementType >
Stack < StackElementType >::Stack()
{
	topIndex = -1;
}

template < class StackElementType >
void
Stack < StackElementType >::push(StackElementType item)
{
	++topIndex;
	// ensure array bounds not exceeded
	assert(topIndex < maxStackSize);
	stackArray[topIndex] = item;
}

template < class StackElementType >
StackElementType
Stack < StackElementType >::pop()
{
	// ensure array bounds not exceeded
	assert(topIndex >= 0);
	int returnIndex(topIndex);
	--topIndex;
	return stackArray[returnIndex];
}

template < class StackElementType >
StackElementType
Stack < StackElementType >::top()
{
	// ensure array bounds not exceeded
	assert(topIndex >= 0);
	return stackArray[topIndex];
}

template < class StackElementType >
bool
Stack < StackElementType >::isEmpty()
{
	return bool(topIndex == -1);
}

template < class StackElementType >
bool
Stack < StackElementType >::isFull()
{
	return topIndex == maxStackSize - 1;
}

#endif