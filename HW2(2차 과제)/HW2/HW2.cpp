#include "singly_linked_list.h"
#include "stack.h"
#include "queue.h"
#include <iostream>
#include <assert.h>
#include <string>
#include <stack>
#include <queue>
#include <list>

using namespace std;


int main()
{
    cout << "전자정보공학부 IT융합과 20170586 박재석" << endl;

    // list 클래스를 활용한 객체 생성
    cout << "List로 출력하는 경우" << endl;
    SingleLinked_List<int> List; //리스트 정적할당
    List.AddNode(8);
    List.AddNode(2);
    List.AddNode(0);
    List.AddNode(0);
    List.AddNode(7);
    List.AddNode(1);
    List.AddNode(3);
    List.Show();

    // stack 클래스를 활용한 객체 생성
    cout << "-------------------------------------" << endl;
    cout << "Stack으로 출력하는 경우" << endl;
    stack<int> st;
    st.push(8);
    st.push(2);
    st.push(0);
    st.push(0);
    st.push(7);
    st.push(1);
    st.push(3);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    // queue 클래스를 활용한 객체 생성
    cout << "-------------------------------------" << endl;
    cout << "Queue으로 출력하는 경우" << endl;
    queue<int> q;
    q.push(8);
    q.push(2);
    q.push(0);
    q.push(0);
    q.push(7);
    q.push(1);
    q.push(3);

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    

    return 0;
}
