#pragma once
#include <string>
using namespace std;

class CPhone
{
public:
	CPhone();
	CPhone(string strName, int nBirthday);


private:
	string m_strName;
	int m_nBirthday;
public:
	string GetName();
	int GetBirthday();
	void SetName(string strName);
	void SetBirthday(int nBirthday);
	// void print();
	friend ostream& operator << (ostream &outStream, const CPhone &aPhone);
};

