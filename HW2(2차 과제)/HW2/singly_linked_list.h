//전자정보공학부 IT융합과 20170586 박재석
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
	SingleLinked_List() : head(nullptr), tail(nullptr) {} // 생성자 리스트
	~SingleLinked_List() {} //소멸자

	void AddNode(T _value) { // 노드 추가하기(back)
		Node<T> *node = new Node<T>;

		size++;
		node->value = _value;
		node->next = nullptr;

		if (head == nullptr) // 만약 머리가 없을경우
		{
			head = node;
			tail = node;
		}
		else // 만약 머리가 있을경우 뒤에 연결 
		{ 
			tail->next = node;
			tail = tail->next; 
		}		
	}



	void RemoveNode(T _value) { // 찾는 값 노드 지우기
		Node<T>* ptr = head; 
		Node<T>* tmp = ptr;

		while (ptr != nullptr)  // ptr 반복
		{
			if (ptr->value == _value)  //만약 값을 찾앗다면 
			{
				break; 
			} 
			else 
			{
			tmp = ptr; //목표의 전 노드 
			ptr = ptr->next; 
			} 
		}

		if (ptr == nullptr) 
		{ 
			cout << "찾을 수 없는 노드 입니다" << endl; 
		}
		else 
		{
			size--; 
			cout << "삭제된 노드의 값: " << ptr->value << endl; 
			tmp->next = ptr->next; //삭제할 노드를 제외하고 연결 
			delete ptr; // 동적 할당 해제 
		}
	}

	void Show() // 리스트 안에 값 보여주기 
	{ 
		Node<T> *node = head; 
		while (node != nullptr) // 노드값이 null 
		{ 
			cout << node->value << " ";
			node = node->next; 
		}
		cout << endl; 
	}

	void DeleteList() // 리스트 삭제하기 (동적할당 풀기) 
	{
		Node<T> *ptr = head; 
		while (ptr != nullptr) 
		{
			head = ptr->next; 
			delete ptr; 
			ptr = head; 
		} 
		delete head; // null 포인터 삭제 
		size = 0; 
		cout << "리스트가 삭제되었습니다" << endl; 
	}

	void RemoveTail() // 꼬리(back) 삭제하기 
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
		delete ptr; // 꼬리 동적할당 해제 
	}

	void RemoveHead() // 헤드(front) 삭제하기 
	{ 
		Node<T> *ptr = head; 
		head = ptr->next; 
		size--; 
		delete ptr; 
	}

	void AddHead(T _value) // 헤드(front)에 값넣기 
	{ 
		Node<T> *ptr = new Node<T>(); 
		size++; 
		ptr->next = head;
		ptr->value = _value;
		head = ptr; 
	}

	void AddPosition(int _index, T _value) 
	{
		if (size < _index || 0>_index) // 인덱스가 잘못될 경우 
		{
			cout << "해당하는 인덱스 값은 없습니다." << endl; 
			return; 
		} 
		Node<T> *ptr = head; Node<T> *tmp = ptr;
		Node<T> *node = new Node<T>; //새로 추가된 노드 
		
		node->value = _value;
		node->next = nullptr; 
		for (int i = 0; i < _index-1; i++) 
		{ 
			tmp = ptr; // 들어갈 노드의 전 위치 
			ptr = ptr->next; // 들어갈 노드의 위치 
		} 
		tmp->next = node; 
		node->next = ptr; //새노드는 기존에 있는 노드위치를 가리킨다.
		size++; 
	}

	void SearchValue(T _value) // 원하는 값이 몇 번쨰에 있는지 확인하기 
	{
		Node<T> *ptr = head; 
		int index = 0; 
		bool isFind = false; //찾앗는지 확인하는 bool 값 
		
		while (ptr != nullptr)
		{ 
			index++;
			if (ptr->value == _value) // ptr 값이랑 같을떄 인덱스값 반환
			{
				cout << _value << " 값은 인덱스 " << index << " 번쨰에 있습니다" << endl; 
				isFind = true; 
				break; 
			} 
			ptr = ptr->next; 
		} 
		//못찾았을 경우 
		if (isFind == false)
		{
			cout << _value << " 값은 리스트 안에 없습니다. " << endl; 
		}
	}

	int Size() // 리스트 크기를 반환 
	{ 
		return size; 
	}

private:
	Node<T> *head; // head
	Node<T> *tail; // tail
	int size = 0; // 링크 길이
};
