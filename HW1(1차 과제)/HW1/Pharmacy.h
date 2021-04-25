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
	Pharmacy();			//�⺻ ������
	Pharmacy(string m_name, int m_distance, int m_hold, int m_arr_time);		//������
	~Pharmacy();

	//��� �Լ�
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
	// Precondition : �� �Լ��� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, string���� ��ȯ�ϹǷ�, = ������ �������μ� string ������ ���� �Ҵ����� �� �ִ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� name(�̸�)�� ��ȯ�Ѵ�.

	int getDistance();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, int���� ��ȯ�ϹǷ�, = ������ �������μ� int ������ ���� �Ҵ����� �� �ִ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� distance(�Ÿ�)�� ��ȯ�Ѵ�.

	int getHold();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, int���� ��ȯ�ϹǷ�, = ������ �������μ� int ������ ���� �Ҵ����� �� �ִ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� hold(����ũ ������)�� ��ȯ�Ѵ�.

	int getArr_time();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, int���� ��ȯ�ϹǷ�, = ������ �������μ� int ������ ���� �Ҵ����� �� �ִ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� arr_time(���� �ð�)�� ��ȯ�Ѵ�.

	// set �Լ�
	void setName(string m_name);
	// Precondition : �� �Լ��� ���ڷ� string�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� name�� ���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	void setDistance(int m_distance);
	// Precondition : �� �Լ��� ���ڷ� int�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� m_distance�� ���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	void setHold(int m_hold);
	// Precondition : �� �Լ��� ���ڷ� int�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� m_hold�� ���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	void setArr_time(int m_arr_time);
	// Precondition : �� �Լ��� ���ڷ� int�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� m_arr_time�� ���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	bool operator == (Pharmacy& pharmacy_a) const {
		// Precondition : �� �Լ��� ���ڷ� Pharmacy Ŭ���� ������ �޴´�. 
		//				  ��, �Լ��� ȣ���� ��ü�� �ٲ��� ���� ���̴�. (const)
		// Postconditions : �� �Լ��� ����Ǹ�, �ռ� ���� ��ó�� �Լ��� ȣ���� ��ü�� �ٲ��� �ʴ´�.
		//					�ٸ�, ȣ��� ��ü�� ���� �ڽ��� Ŭ���� ���� �� �̸�(Ŭ���� �� ��� ����)�� ���Ͽ�, true �Ǵ� false�� �����Ѵ�.
		// return : (���ڷ� ���� Ŭ���� ���� �� �̸�)�� (���� ���� Ŭ���� ���� �� �̸�)�� ���� ��� true(1)��, �ٸ� ��� false(0)�� ��ȯ�Ѵ�.
		return (name == pharmacy_a.getName());
	}

	bool operator < (Pharmacy& pharmacy_a) const {
		// Precondition : �� �Լ��� ���ڷ� Pharmacy Ŭ���� ������ �޴´�. 
		//				  ��, �Լ��� ȣ���� ��ü�� �ٲ��� ���� ���̴�. (const)
		// Postconditions : �� �Լ��� ����Ǹ�, �ռ� ���� ��ó�� �Լ��� ȣ���� ��ü�� �ٲ��� �ʴ´�.
		//					�ٸ�, ȣ��� ��ü�� ���� �ڽ��� Ŭ���� ���� �� �̸�(Ŭ���� �� ��� ����)�� ���Ͽ�, true �Ǵ� false�� �����Ѵ�.	
		// return : (���ڷ� ���� Ŭ���� ���� �� �̸�)�� (���� ���� Ŭ���� ���� �� �̸�)�� ���� ��� true(1)��, �ٸ� ��� false(0)�� ��ȯ�Ѵ�.
		return (name < pharmacy_a.getName());
	}

	bool operator <= (Pharmacy& pharmacy_a) const {
		// Precondition : �� �Լ��� ���ڷ� Pharmacy Ŭ���� ������ �޴´�.
		//				  ��, �Լ��� ȣ���� ��ü�� �ٲ��� ���� ���̴�. (const)
		// Postconditions : �� �Լ��� ����Ǹ�, �ռ� ���� ��ó�� �Լ��� ȣ���� ��ü�� �ٲ��� �ʴ´�.
		//					�ٸ�, ȣ��� ��ü�� ���� �ڽ��� Ŭ���� ���� �� �̸�(Ŭ���� �� ��� ����)�� ���Ͽ�, true �Ǵ� false�� �����Ѵ�.	
		// return : (���ڷ� ���� Ŭ���� ���� �� �̸�)�� (���� ���� Ŭ���� ���� �� �̸�)�� ���� ��� true(1)��, �ٸ� ��� false(0)�� ��ȯ�Ѵ�.
		return (name == pharmacy_a.getName() || name < pharmacy_a.getName());
	}

	bool operator > (Pharmacy& pharmacy_a) const {
		// Precondition : �� �Լ��� ���ڷ� Pharmacy Ŭ���� ������ �޴´�. 
		//				  ��, �Լ��� ȣ���� ��ü�� �ٲ��� ���� ���̴�. (const)
		// Postconditions : �� �Լ��� ����Ǹ�, �ռ� ���� ��ó�� �Լ��� ȣ���� ��ü�� �ٲ��� �ʴ´�.
		//					�ٸ�, ȣ��� ��ü�� ���� �ڽ��� Ŭ���� ���� �� �̸�(Ŭ���� �� ��� ����)�� ���Ͽ�, true �Ǵ� false�� �����Ѵ�.	
		// return : (���ڷ� ���� Ŭ���� ���� �� �̸�)�� (���� ���� Ŭ���� ���� �� �̸�)�� ���� ��� true(1)��, �ٸ� ��� false(0)�� ��ȯ�Ѵ�.
		return (name > pharmacy_a.getName());
	}

	bool operator >= (Pharmacy& pharmacy_a) const {
		// Precondition : �� �Լ��� ���ڷ� Pharmacy Ŭ���� ������ �޴´�.
		//				  ��, �Լ��� ȣ���� ��ü�� �ٲ��� ���� ���̴�. (const)
		// Postconditions : �� �Լ��� ����Ǹ�, �ռ� ���� ��ó�� �Լ��� ȣ���� ��ü�� �ٲ��� �ʴ´�.
		//					�ٸ�, ȣ��� ��ü�� ���� �ڽ��� Ŭ���� ���� �� ���� �ð�(Ŭ���� �� ��� ����)�� ���Ͽ�,
		//					true �Ǵ� false�� �����Ѵ�.
		// return : (���ڷ� ���� �� �� ���� �ð�)�� ���� (���� ���� �� �� 
		// ���� �ð�)�� ���ų� Ŭ�� ��� true(1)��, �ٸ� ��� false(0)�� ��ȯ�Ѵ�.
		return (name == pharmacy_a.getName() || name > pharmacy_a.getName());
	}

private:
	string name;	//�౹ �̸�
	int distance;	//�Ÿ�
	int hold;	//����ũ ������
	int arr_time;	//���� �ð�
	int minutes;
};