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


// PreConditions : �� �Լ��� �Է°����� ������ �迭�� �� �տ������� ������ ���������� ���� ������ ����
// PostConditions : �� �Լ��� ������ ������ ���� �ȿ���, �� �ڿ��� ���� ū ���� ���� ��
// Return : void���̹Ƿ� Return���� ������ �Է� ���ڷ� ���� �迭�� ���ϰ� ��
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