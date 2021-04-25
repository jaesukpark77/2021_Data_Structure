#include "Pharmacy.h"
#include<string.h>
using namespace std;

Pharmacy::Pharmacy()
{
}

Pharmacy::Pharmacy(string m_name, int m_distance, int m_hold, int m_arr_time)
{
	name = m_name;
	distance = m_distance;
	hold = m_hold;
	arr_time = m_arr_time;
}

Pharmacy::~Pharmacy()
{
}

void Pharmacy::readTime(bool& errorFlag)
{
	// The time must be formatted as <HH>:<MM><AMorPM>, where
	// <HH> is an int in the range 0 to 12, <MM> is an int in
	// the range 0 to 59, and <AMorPM> is either AM or PM.
	enum AM_PM { AM, PM } AM_or_PM;
	int hour, minute;
	const char delimiter = ':';

	// Assume that the format is bad -- once valid data is extracted,
	// reset errorFlag to false
	errorFlag = true;
	// formatted input -- fail if not an int
	if (!(cin >> hour))
		return;
	if (hour < 0 || hour > 12)
		return;
	char c;
	cin >> c;
	if (c != delimiter)
		return;
	if (!(cin >> minute)) // formatted input
		return;
	if (minute < 0 || minute > 59)
		return;
	cin >> c;
	if (c == 'A' || c == 'a')
		AM_or_PM = AM;
	else if (c == 'P' || c == 'p')
		AM_or_PM = PM;
	else
		return;
	cin >> c;
	if (c != 'M' && c != 'm')
		return;
	errorFlag = false;
	if (hour == 12)
		minutes = minute;
	else
		minutes = hour * 60 + minute;
	if (AM_or_PM == PM)
		minutes += 60 * 12;
}

int Pharmacy::subtractTimes(Pharmacy t)
{
	return minutes - t.minutes;
}


int Pharmacy::AddTime(int nTime)
{
	return minutes + nTime;
}

string Pharmacy::getName()
{
	return name;
}

int Pharmacy::getDistance()
{
	return distance;
}

int Pharmacy::getHold()
{
	return hold;
}

int Pharmacy::getArr_time()
{
	return arr_time;
}

void Pharmacy::setName(string m_name)
{
	name = m_name;
}

void Pharmacy::setDistance(int m_distance)
{
	distance = m_distance;
}

void Pharmacy::setHold(int m_hold)
{
	hold = m_hold;
}

void Pharmacy::setArr_time(int m_arr_time)
{
	arr_time = m_arr_time;
}