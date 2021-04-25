#include "selection_sort.h"



void swapElements_selection(Pharmacy a[], int first, int last)
{
	Pharmacy temp = a[first];
	a[first] = a[last];
	a[last] = temp;
}


int maxSelect(Pharmacy a[], int n)
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


// PreConditions : 이 함수는 입력값으로 정수형 배열과 맨 앞에서부터 어디까지 정렬할지를 양의 정수로 받음
// PostConditions : 이 함수가 끝나면 정렬할 범위 안에서, 맨 뒤에는 제일 큰 값이 오게 됨
// Return : void형이므로 Return값이 없으며 입력 인자로 받은 배열이 변하게 됨
void SelectionSort(Pharmacy a[], int n)
{
	int last(n - 1);
	int maxPos;
	while (last > 0) {
		// invariant: a[last+1] ... a[n-1] is sorted &&
		//    everything in a[0] ... a[last] <= everything in a[last+1] ... a[n-1]
		maxPos = maxSelect(a, last + 1); // last+1 is length from 0 to last
		swapElements_selection(a, maxPos, last);
		last--;
	}
}