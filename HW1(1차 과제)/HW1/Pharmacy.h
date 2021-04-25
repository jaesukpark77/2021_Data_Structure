#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pharmacy
{//
// Characteristics:
//
//   A Time consists of some number of hours and minutes. 
//	 For example, 0335 is 3 hours(3 AM) and 35 minutes.
//	 Another example, 1549 is 15 hours(3 PM) and 49 minutes.
//	 A time has correct lange, 0 to 23.
//	 A minute has correct lange, 0 to 59.
//
//   All Times are assumed to fall on the same day.
//

public:
	Pharmacy();			//기본 생성자
	Pharmacy(string m_name, int m_distance, int m_hold, int m_arr_time);		//생성자
	~Pharmacy();

	//멤버 함수
public:
	void readTime(bool& errorFlag);
	//   Precondition: Standard input has characters available.
	//   Postconditions: Leading whitespace characters are ignored; 
	//      readTime attempts to read, from standard input, a time in 
	//      the format <HH>:<MM><A>, where <HH> is an integer between 
	//      1 and 12, <MM> is an integer between 0 and 59, and <A> is 
	//      either "AM" or "PM". If a properly formatted time can be 
	//      read, errorFlag is set to false, and the value of the Time
	//      variable is set to the time read; otherwise, errorFlag is 
	//      set to true.
	int subtractTimes(Pharmacy t);
	//   Precondition: This Time variable contains a proper value.
	//   Postcondition: None.
	//   Returns: The difference, in minutes, between this Time and Time t. 
	//      If this Time occurs prior to Time t, the returned difference 
	//      is negative.

	int AddTime(int nTime);

	string getName();
	// Precondition : 이 함수는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, string값을 반환하므로, = 우측에 있음으로서 string 변수에 값을 할당해줄 수 있다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 name(이름)을 반환한다.

	int getDistance();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, int값을 반환하므로, = 우측에 있음으로서 int 변수에 값을 할당해줄 수 있다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 distance(거리)을 반환한다.

	int getHold();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, int값을 반환하므로, = 우측에 있음으로서 int 변수에 값을 할당해줄 수 있다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 hold(마스크 보유량)을 반환한다.

	int getArr_time();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, int값을 반환하므로, = 우측에 있음으로서 int 변수에 값을 할당해줄 수 있다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 arr_time(도착 시간)을 반환한다.

	// set 함수
	void setName(string m_name);
	// Precondition : 이 함수는 인자로 string형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 name에 인자로 받은 값을 할당하게 된다.
	// return : void형이므로 리턴값이 없다.

	void setDistance(int m_distance);
	// Precondition : 이 함수는 인자로 int형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 m_distance에 인자로 받은 값을 할당하게 된다.
	// return : void형이므로 리턴값이 없다.

	void setHold(int m_hold);
	// Precondition : 이 함수는 인자로 int형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 m_hold에 인자로 받은 값을 할당하게 된다.
	// return : void형이므로 리턴값이 없다.

	void setArr_time(int m_arr_time);
	// Precondition : 이 함수는 인자로 int형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 m_arr_time에 인자로 받은 값을 할당하게 된다.
	// return : void형이므로 리턴값이 없다.

	bool operator == (Pharmacy& pharmacy_a) const {
		// Precondition : 이 함수는 인자로 Pharmacy 클래스 변수를 받는다. 
		//				  단, 함수로 호출한 객체는 바뀌지 않을 것이다. (const)
		// Postconditions : 이 함수가 종료되면, 앞서 말한 것처럼 함수로 호출한 객체는 바뀌지 않는다.
		//					다만, 호출된 객체와 현재 자신의 클래스 변수 중 이름(클래스 안 멤버 변수)을 비교하여, true 또는 false를 리턴한다.
		// return : (인자로 받은 클래스 변수 중 이름)과 (현재 가진 클래스 변수 중 이름)이 같을 경우 true(1)를, 다를 경우 false(0)를 반환한다.
		return (name == pharmacy_a.getName());
	}

	bool operator < (Pharmacy& pharmacy_a) const {
		// Precondition : 이 함수는 인자로 Pharmacy 클래스 변수를 받는다. 
		//				  단, 함수로 호출한 객체는 바뀌지 않을 것이다. (const)
		// Postconditions : 이 함수가 종료되면, 앞서 말한 것처럼 함수로 호출한 객체는 바뀌지 않는다.
		//					다만, 호출된 객체와 현재 자신의 클래스 변수 중 이름(클래스 안 멤버 변수)을 비교하여, true 또는 false를 리턴한다.	
		// return : (인자로 받은 클래스 변수 중 이름)과 (현재 가진 클래스 변수 중 이름)이 같을 경우 true(1)를, 다를 경우 false(0)를 반환한다.
		return (name < pharmacy_a.getName());
	}

	bool operator <= (Pharmacy& pharmacy_a) const {
		// Precondition : 이 함수는 인자로 Pharmacy 클래스 변수를 받는다.
		//				  단, 함수로 호출한 객체는 바뀌지 않을 것이다. (const)
		// Postconditions : 이 함수가 종료되면, 앞서 말한 것처럼 함수로 호출한 객체는 바뀌지 않는다.
		//					다만, 호출된 객체와 현재 자신의 클래스 변수 중 이름(클래스 안 멤버 변수)을 비교하여, true 또는 false를 리턴한다.	
		// return : (인자로 받은 클래스 변수 중 이름)과 (현재 가진 클래스 변수 중 이름)이 같을 경우 true(1)를, 다를 경우 false(0)를 반환한다.
		return (name == pharmacy_a.getName() || name < pharmacy_a.getName());
	}

	bool operator > (Pharmacy& pharmacy_a) const {
		// Precondition : 이 함수는 인자로 Pharmacy 클래스 변수를 받는다. 
		//				  단, 함수로 호출한 객체는 바뀌지 않을 것이다. (const)
		// Postconditions : 이 함수가 종료되면, 앞서 말한 것처럼 함수로 호출한 객체는 바뀌지 않는다.
		//					다만, 호출된 객체와 현재 자신의 클래스 변수 중 이름(클래스 안 멤버 변수)을 비교하여, true 또는 false를 리턴한다.	
		// return : (인자로 받은 클래스 변수 중 이름)과 (현재 가진 클래스 변수 중 이름)이 같을 경우 true(1)를, 다를 경우 false(0)를 반환한다.
		return (name > pharmacy_a.getName());
	}

	bool operator >= (Pharmacy& pharmacy_a) const {
		// Precondition : 이 함수는 인자로 Pharmacy 클래스 변수를 받는다.
		//				  단, 함수로 호출한 객체는 바뀌지 않을 것이다. (const)
		// Postconditions : 이 함수가 종료되면, 앞서 말한 것처럼 함수로 호출한 객체는 바뀌지 않는다.
		//					다만, 호출된 객체와 현재 자신의 클래스 변수 중 도착 시간(클래스 안 멤버 변수)을 비교하여,
		//					true 또는 false를 리턴한다.
		// return : (인자로 받은 값 중 도착 시간)에 비해 (현재 가진 값 중 
		// 도착 시간)이 같거나 클을 경우 true(1)를, 다를 경우 false(0)를 반환한다.
		return (name == pharmacy_a.getName() || name > pharmacy_a.getName());
	}

private:
	string name;	//약국 이름
	int distance;	//거리
	int hold;	//마스크 보유량
	int arr_time;	//도착 시간
	int minutes;
};