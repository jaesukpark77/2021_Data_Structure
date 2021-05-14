#include <iostream>
#include <stdio.h>
using namespace std;

void insertionSort(int a[], int n);
void insertNextItem(int a[], int i);        // in cx3 6.cpp

int main()
{
    int arraynum;

    cout << "입력할 정수의 갯수를 입력해주세요 : ";
    cin >> arraynum;

    int* arr = new int[arraynum];

    for (int i = 0; i < arraynum; i++)
    {
        cout << i + 1 << "번째 입력 : ";
        cin >> arr[i];
    }

    insertionSort(arr, arraynum);

    for (int i = 0; i < arraynum; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}

void insertionSort(int a[], int n)
{
    // Precondition: a is an array with subscripts ranging from 0 to n-1
    int i;
    for (i = 1; i < n; i++)
    {   // Loop invariant: items in range from 0 to i-1 are sorted;
        // items from i to n-1 have not yet been examined.
        insertNextItem(a, i); // see cx3 6.cpp
    }
    // Postcondition: array a is sorted
}


void insertNextItem(int a[], int i)
{
    //Precondition : array a is sorted from 0 to i-1
    int newItem(a[i]), insertPos(i);
    for (; insertPos && newItem < a[insertPos - 1] ; insertPos--)
    { 
        //Loop Invariant : newItem <= a[insertPos+1] .. a[i] && a[insertPos+1]  .. a[i] are sorted
        a[insertPos] = a[insertPos - 1];
    }
    a[insertPos] = newItem;
    // Postcondition: array a is sorted from 0 to i
}

