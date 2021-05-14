#include <iostream>
using namespace std;

#define SIZE 7

// Quicksort
int partition(int a[], int first, int last);
void quicksort(int a[], int first, int last)
{
	// precondition: a is an array; 
	//    The portion to be sorted runs from index first to index last inclusive.
	if (first >= last) // Base Case -- nothing to sort, so just return
		return;
	// Otherwise, we’re in the recursive case.
	// The partition function uses the item in a[first] as the pivot
	// and returns the position of the pivot -- split -- after the partition.
	int split(partition(a, first, last));

	// Recursively, sort the two partitions.
	quicksort(a, first, split - 1);
	quicksort(a, split + 1, last);
	// postcondition: a is sorted in ascending order 
	// between first and last inclusive.
}

void swapElements(int a[], int first, int last); // see Exercise 5-12
int partition(int a[], int first, int last)
{
	int lastSmall(first), i;

	for (i = first + 1; i <= last; i++)
		// loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
		//    a[lastSmall+1]...a[i-1] > a[first]

		if (a[i] <= a[first]) { // key comparison
			++lastSmall;
			swapElements(a, lastSmall, i);
		}

	swapElements(a, first, lastSmall); // put pivot into correct position
	// postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
	//    a[lastSmall+1]...a[last] > a[lastSmall]
	return lastSmall; // this is the final position of the pivot -- the split index
}

void swapElements(int a[], int first, int last)
{
	int temp = a[first];
	a[first] = a[last];
	a[last] = temp;
}

int main(void) {
	int a[SIZE] = { 3, 2, 4, 1, 7, 6, 5 };

	quicksort(a, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}