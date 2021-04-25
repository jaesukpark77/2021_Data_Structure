#pragma once

// the type of the individual elements in the list is defined here

typedef int ListElementType;

// the maximum size for lists is defined here

const int maxListSize = 1000;

class List {
public:
	List();
	void insert(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
private:
	ListElementType listArray[maxListSize];
	int numberOfElements;
	int currentPosition;
};
