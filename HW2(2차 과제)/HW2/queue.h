//전자정보공학부 IT융합과 20170586 박재석
#pragma once
#include <assert.h> 

const int maxQueue = 200;

template < class queueElementType >
class Queue {
public:
	Queue();
	~Queue(); //소멸자
	void enqueue(queueElementType e);
	queueElementType dequeue();
	queueElementType front();
	bool isEmpty();
	bool isFull();
private:
	int f; // marks the front of the queue
	int r; // marks the rear of the queue
	queueElementType elements[maxQueue];
	int m_nElemnet; // number of elements;
};
int nextPos(int p)
{
	if (p == maxQueue - 1) // at end of circle
		return 0;
	else
		return p + 1;
}
template < class queueElementType >
Queue < queueElementType >::Queue()
{
	// start both front and rear at 0
	f = 0;
	r = 0;
	m_nElemnet = 0; // zero at the initial state
}
template < class queueElementType >
Queue < queueElementType >::~Queue()
{
	// no memory deallocation is required
}
template < class queueElementType >
void
Queue < queueElementType >::enqueue(queueElementType e)
{
	// add e to the rear of the queue, advancing r to next position
	// assert(nextPos(r) != f); // is not full?
	assert(!isFull());
	r = nextPos(r);
	elements[r] = e;
	m_nElemnet++; // increase the number of elements
}
template < class queueElementType >
queueElementType
Queue < queueElementType >::dequeue()
{
	// advance front of queue, return value of element at the front
	// assert(f != r); // is  not empty?
	assert(!isEmpty());
	f = nextPos(f);
	m_nElemnet--; // decrease the number of elements
	return elements[f];
}
template < class queueElementType >
queueElementType
Queue < queueElementType >::front()
{
	// return value of element at the front
	// assert(f != r);
	assert(!isEmpty());
	return elements[nextPos(f)];
}
template < class queueElementType >
bool
Queue < queueElementType >::isEmpty()
{
	// return true if the queue is empty, that is,
	// if front is the same as rear
	// return bool(f == r);
	return bool(m_nElemnet == 0);
}
template < class queueElementType >
bool
Queue < queueElementType >::isFull()
{
	// return true if the queue is full, that is,
	// if front is a step forward to rear
	// return bool(nextPos(r) = f);
	return bool(m_nElemnet == maxQueue);
}