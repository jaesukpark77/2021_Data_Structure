//전자정보공학부 IT융합과 20170586 박재석
#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	cout << "전자정보공학부 IT융합과 20170586 박재석" << endl;
	/*Queue<char> chQ;

	chQ.enqueue('a');
	chQ.enqueue('b');
	chQ.enqueue('c');
	chQ.enqueue('d');

	while (!chQ.isEmpty())
	{
		char chVal = chQ.dequeue();
		cout << chVal << endl;
	}*/
	char c;
	Queue < char > q;

	// read characters until '.' found, adding each to Q and S.
	while (1) {
		cin >> c;
		if (c == '.') break; // when '.' entered, leave the loop
		q.enqueue(c);
	}
	while (!q.isEmpty()) {
		cout << "Q: " << q.dequeue() << '\t';
	}
	return 0;

}
