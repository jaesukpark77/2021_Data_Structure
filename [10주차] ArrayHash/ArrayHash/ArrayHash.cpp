#include <iostream>
#include "Table.h"
#include "CPhone.h"

using namespace std;

int StringToInt(string strName);

int main()
{
	Table<int, int> myTable;

	myTable.insert(20200421, 20200421);
	myTable.insert(20200422, 20200422);
	myTable.insert(20200423, 20200423);
	myTable.insert(20200424, 20200424);
	myTable.insert(20200425, 20200425);
	myTable.insert(20200426, 20200426);
	myTable.insert(20200427, 20200427);

	myTable.dump();
	myTable.deleteKey(20200423);
	myTable.deleteKey(20200424);

	myTable.insert(20200412, 20200412);
	myTable.dump();


	Table<int, CPhone> myTable2;

	myTable2.insert(20200421, CPhone("John", 20200421));
	myTable2.insert(20200422, CPhone("David", 20200422));
	myTable2.insert(20200423, CPhone("Mary", 20200423));

	myTable2.dump();

	CPhone aPhone;
	myTable2.lookup(20200421, aPhone);
	// aPhone.print();
	// cout << aPhone.GetName() << " " << aPhone.GetBirthday() << endl;
	cout << aPhone;

	Table<int, CPhone> myTable3;

	myTable3.insert(StringToInt("John"), CPhone("John", 20200421));
	myTable3.insert(StringToInt("David"), CPhone("David", 20200422));
	myTable3.insert(StringToInt("Mary"), CPhone("Mary", 20200423));

	CPhone aPhone3;
	myTable3.lookup(20200421, aPhone3);
	cout << aPhone;


	return 0;
}

int StringToInt(string strName) {
	int nSum = 0;
	int nLength = strName.size();
	for (int nIndex = 0; nIndex < nLength; nIndex++)
	{
		nSum += strName.at(nIndex);
	}
	return nSum;
}
