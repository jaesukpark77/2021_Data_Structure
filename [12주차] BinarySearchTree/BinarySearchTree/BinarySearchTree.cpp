//전자정보공학부 IT융합과 20170586박재석
#include <iostream>
#include "BinaryTree.h"
#include "BST.h"
using namespace std;

int main()
{
	cout << "전자정보공학부 IT융합과 20170586박재석\n" << endl;
	typedef BST < int > intBST;
	typedef intBST* intBSTPtr;

	intBSTPtr b(new intBST);
	b->insert(17);
	b->insert(10);
	b->insert(26);
	b->insert(6);
	b->insert(14);

	b->insert(20);
	b->insert(28);
	b->insert(11);
	b->insert(31);
	b->insert(37);
	b->insert(12);
	// is 11 in the tree?
	intBSTPtr get11((BST<int>*)b->retrieve(11));
	if (get11->isEmpty())
		cout << "11 not found.\n";
	else
		cout << "11 found.\n";
	// is 13 in the tree?

	intBSTPtr get13((BST<int>*)b->retrieve(13));
	if (get13->isEmpty())
		cout << "13 not found.\n";
	else
		cout << "13 found.\n";
	return 0;
}