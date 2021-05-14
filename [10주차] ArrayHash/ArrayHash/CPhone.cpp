#include <iostream>
#include "CPhone.h"
using namespace std;

CPhone::CPhone()
{
	m_strName = "";
	m_nBirthday = 00000000;
}

CPhone::CPhone(string strName, int nBirthday)
{
	m_strName = strName;
	m_nBirthday = nBirthday;
}


string CPhone::GetName()
{
	
	return m_strName;
}


int CPhone::GetBirthday()
{
	return m_nBirthday;
}


void CPhone::SetName(string strName)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_strName = strName;
}


void CPhone::SetBirthday(int nBirthday)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_nBirthday = nBirthday;
}

/*
void CPhone::print()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	cout << "Name: " << m_strName << " "  << "Birthday: " << m_nBirthday << endl;
}*/

ostream& operator << (ostream& outStream, const CPhone& aPhone)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	outStream << "Name: " << aPhone.m_strName << " " << "Birthday: " << aPhone.m_nBirthday << endl;
	return outStream;
}
