#include "List.h"
#include <assert.h>

List::List()
{
	// Initialize an empty List
	head = 0;
	tail = 0;
	current = 0;
}

List::~List()
{
	while (head != 0) {
		Link delNode = head;
		head = head->next;
		delete delNode;
	}
}

////tail애 insert 하는 함수로 수정
//void List::insert(const ListElementType& elem)
//{
//	Link addedNode = new Node;
//	assert(addedNode); // check to make sure node was allocated
//	addedNode->elem = elem;
//	if (head == 0) // list was empty -- set head
//		head = addedNode;
//	else
//		tail->next = addedNode;
//	tail = addedNode;
//	addedNode->next = 0;
//}
//
////haed애 insert 하는 함수로 수정
//void List::insert(const ListElementType& elem)
//{
//	Link addedNode = new Node;
//	assert(addedNode); // check to make sure node was allocated
//	addedNode->elem = elem;
//	if (head == 0) { // list was empty -- set head
//		tail = addedNode;
//	}
//	addedNode->next = head; //처음일때는 head가 null이고 아니면 다음 노드의 주소값
//	head = addedNode; // 앞줄과 순서가 바뀌면 곤란하다. 반드시 이순서로
//}

void List::insert(const ListElementType& elem)
{
	// precondition: list is in order
	Link addedNode(new Node);
	assert(addedNode);
	addedNode->elem = elem;
	// Special case: if the existing list is empty, or if the new data
	// is less than the smallest item in the list, the new node is added
	// to the front of the list
	if (head == 0 || elem <= head->elem) {
		addedNode->next = head;
		head = addedNode;
	}
	else {
		// find the pointer to the node that is the predecessor
		// to the new node in the in-order list
		Link pred(head);
		// assertion: pred->elem <= addedNode->elem
		while (pred->next != 0 && pred->next->elem <= addedNode->elem)
			// loop invariant: pred->next != 0 && pred->next->elem <= elem
			pred = pred->next;
		// assertion 7-1: (pred->elem <= addedNode->elem) &&
		//    (addedNode->elem <= pred->next->elem || pred->next == 0)
		addedNode->next = pred->next;
		pred->next = addedNode;
		// assertion: pred->elem <= pred->next->elem &&
		//    (pred->next->elem <= pred->next->next->elem || pred->next->next == 0)
	}
	// postcondition: list is in order, with elem added in proper position
}


bool List::first(ListElementType& elem)
{
	// After calling first, current points to first item in list
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}

bool List::next(ListElementType& elem)
{
	// with proper use, current should always be nonzero
	assert(current);

	// After each call, current always points to the item
	// that next has just returned.
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}
}
