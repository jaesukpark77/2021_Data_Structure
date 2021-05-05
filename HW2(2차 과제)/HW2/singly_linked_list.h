//�����������к� IT���հ� 20170586 ���缮
#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct  Node
{
public: 
	T value;
	struct Node<T>* next = nullptr;
};

template <typename T>
class SingleLinked_List
{
public:
	SingleLinked_List() : head(nullptr), tail(nullptr) {} // ������ ����Ʈ
	~SingleLinked_List() {} //�Ҹ���

	void AddNode(T _value) { // ��� �߰��ϱ�(back)
		Node<T> *node = new Node<T>;

		size++;
		node->value = _value;
		node->next = nullptr;

		if (head == nullptr) // ���� �Ӹ��� �������
		{
			head = node;
			tail = node;
		}
		else // ���� �Ӹ��� ������� �ڿ� ���� 
		{ 
			tail->next = node;
			tail = tail->next; 
		}		
	}



	void RemoveNode(T _value) { // ã�� �� ��� �����
		Node<T>* ptr = head; 
		Node<T>* tmp = ptr;

		while (ptr != nullptr)  // ptr �ݺ�
		{
			if (ptr->value == _value)  //���� ���� ã�Ѵٸ� 
			{
				break; 
			} 
			else 
			{
			tmp = ptr; //��ǥ�� �� ��� 
			ptr = ptr->next; 
			} 
		}

		if (ptr == nullptr) 
		{ 
			cout << "ã�� �� ���� ��� �Դϴ�" << endl; 
		}
		else 
		{
			size--; 
			cout << "������ ����� ��: " << ptr->value << endl; 
			tmp->next = ptr->next; //������ ��带 �����ϰ� ���� 
			delete ptr; // ���� �Ҵ� ���� 
		}
	}

	void Show() // ����Ʈ �ȿ� �� �����ֱ� 
	{ 
		Node<T> *node = head; 
		while (node != nullptr) // ��尪�� null 
		{ 
			cout << node->value << " ";
			node = node->next; 
		}
		cout << endl; 
	}

	void DeleteList() // ����Ʈ �����ϱ� (�����Ҵ� Ǯ��) 
	{
		Node<T> *ptr = head; 
		while (ptr != nullptr) 
		{
			head = ptr->next; 
			delete ptr; 
			ptr = head; 
		} 
		delete head; // null ������ ���� 
		size = 0; 
		cout << "����Ʈ�� �����Ǿ����ϴ�" << endl; 
	}

	void RemoveTail() // ����(back) �����ϱ� 
	{ 
		Node<T> *ptr = head;
		Node<T> *tmp = new Node<T>;
		while (ptr->next != nullptr)
		{ 
			tmp = ptr; 
			ptr = ptr->next; 
		} 
		size--; 
		tail = tmp;
		tail->next = nullptr; 
		delete ptr; // ���� �����Ҵ� ���� 
	}

	void RemoveHead() // ���(front) �����ϱ� 
	{ 
		Node<T> *ptr = head; 
		head = ptr->next; 
		size--; 
		delete ptr; 
	}

	void AddHead(T _value) // ���(front)�� ���ֱ� 
	{ 
		Node<T> *ptr = new Node<T>(); 
		size++; 
		ptr->next = head;
		ptr->value = _value;
		head = ptr; 
	}

	void AddPosition(int _index, T _value) 
	{
		if (size < _index || 0>_index) // �ε����� �߸��� ��� 
		{
			cout << "�ش��ϴ� �ε��� ���� �����ϴ�." << endl; 
			return; 
		} 
		Node<T> *ptr = head; Node<T> *tmp = ptr;
		Node<T> *node = new Node<T>; //���� �߰��� ��� 
		
		node->value = _value;
		node->next = nullptr; 
		for (int i = 0; i < _index-1; i++) 
		{ 
			tmp = ptr; // �� ����� �� ��ġ 
			ptr = ptr->next; // �� ����� ��ġ 
		} 
		tmp->next = node; 
		node->next = ptr; //������ ������ �ִ� �����ġ�� ����Ų��.
		size++; 
	}

	void SearchValue(T _value) // ���ϴ� ���� �� ������ �ִ��� Ȯ���ϱ� 
	{
		Node<T> *ptr = head; 
		int index = 0; 
		bool isFind = false; //ã�Ѵ��� Ȯ���ϴ� bool �� 
		
		while (ptr != nullptr)
		{ 
			index++;
			if (ptr->value == _value) // ptr ���̶� ������ �ε����� ��ȯ
			{
				cout << _value << " ���� �ε��� " << index << " ������ �ֽ��ϴ�" << endl; 
				isFind = true; 
				break; 
			} 
			ptr = ptr->next; 
		} 
		//��ã���� ��� 
		if (isFind == false)
		{
			cout << _value << " ���� ����Ʈ �ȿ� �����ϴ�. " << endl; 
		}
	}

	int Size() // ����Ʈ ũ�⸦ ��ȯ 
	{ 
		return size; 
	}

private:
	Node<T> *head; // head
	Node<T> *tail; // tail
	int size = 0; // ��ũ ����
};
