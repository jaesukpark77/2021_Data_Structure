//전자정보공학부 IT융합과 20170586 박재석
#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	cout << "전자정보공학부 IT융합과 20170586 박재석" << endl;
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
	return 0;
}

