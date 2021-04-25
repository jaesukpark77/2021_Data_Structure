#include <iostream>
using namespace std;

#define SIZE 9

//// desreasing order가 되게 구현
//// 제일 작은 값을 맨 뒤로 가게 하기!
//void SelectionSort(int arr[], int a);

void swapElements(int a[], int maxPos, int last); 
int maxSelect(int a[], int n); 
void SelectionSort(int a[], int n);


int main(void)
{
	int arr[SIZE] = { 30, 65, 72, 51, 85, 31, 44, 55, 20 };

	for (int i = 0; i < SIZE - 1; i++) {
		SelectionSort(arr, SIZE - i);
	}

	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";

	return 0;
}

//// PreConditions : 이 함수는 입력값으로 정수형 배열과 맨 앞에서부터 어디까지 정렬할지를 양의 정수로 받음
//// PostConditions : 이 함수가 끝나면 정렬할 범위 안에서, 맨 뒤에는 제일 작은 값이 오게 됨
//// Return : void형이므로 Return값이 없으며 입력 인자로 받은 배열이 변하게 됨
//void SelectionSort(int arr[], int n)
//{
//	int max(0), temp;
//
//	// min값의 index를 찾음
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[max] < arr[i])
//			max = i;
//	}
//
//	// swap하는 부분
//	temp = arr[n - 1];
//	arr[n - 1] = arr[max];
//	arr[max] = temp;
//}

void swapElements(int a[], int first, int last)
{
	int temp = a[first];
	a[first] = a[last];
	a[last] = temp;
}

int maxSelect(int a[], int n)
{
	int maxPos(0), currentPos(1);
	while (currentPos < n) {
		// Invariant: a[maxPos] >= a[0] ... a[currentPos-1]
		if (a[currentPos] > a[maxPos])
			maxPos = currentPos;
		currentPos++;
	}
	return maxPos;
}

void swapElements(int a[], int maxPos, int last); // see Exercise 5-12
int maxSelect(int a[], int n); // see cx5-4.cpp

void SelectionSort(int a[], int n)
{
	int last(n - 1);
	int maxPos;
	while (last > 0) {
		// invariant: a[last+1] ... a[n-1] is sorted &&
		//    everything in a[0] ... a[last] <= everything in a[last+1] ... a[n-1]
		maxPos = maxSelect(a, last + 1); // last+1 is length from 0 to last
		swapElements(a, maxPos, last);
		last--;
	}
}