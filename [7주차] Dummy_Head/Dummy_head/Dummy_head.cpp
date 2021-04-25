#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List l;
	ListElementType i; // header file defines this to be int
	cout << "Enter items to add to list, add 0 to stop: ";
	cin >> i;
	while (i != 0) {
		l.insert(i);
		cin >> i;
	}
	cout << "Here are the items in the list.\n";
	ListElementType elem;
	bool notEmpty(l.first(elem));
	while (notEmpty) {
		cout << elem << endl;
		notEmpty = l.next(elem);
	}
	cout << " " << endl;

	/*cout << "Here are the items after removed int the list\n";
	ListElementType data;
	bool notDelEmpty(l.first(data));
	if (data == 4)
	{
		l.remove(data);
	}
	while (notDelEmpty) {
		cout << elem << endl;
		notDelEmpty = l.next(elem);
	}
	cout << " " << endl;*/


	return 0;
}

