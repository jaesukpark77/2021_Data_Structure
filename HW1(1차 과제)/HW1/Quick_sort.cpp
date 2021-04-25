#include "Quick_sort.h"

// Code Example 6-6: Quicksort
void quicksort(Pharmacy a[], int first, int last, int& case_number_one_compareCount, int& case_number_one_swapCount, int& case_number_one_calculateCount)
{
	// precondition: a is an array; 
	//    The portion to be sorted runs from index first to index last inclusive.
	case_number_one_compareCount++;
	if (first >= last) // Base Case -- nothing to sort, so just return				   //비교문
		return;
	// Otherwise, we¡¯re in the recursive case.
	// The partition function uses the item in a[first] as the pivot
	// and returns the position of the pivot -- split -- after the partition.
	int split(partition(a, first, last, case_number_one_compareCount, case_number_one_swapCount, case_number_one_calculateCount));

	// Recursively, sort the two partitions.
	case_number_one_calculateCount++;
	quicksort(a, first, split - 1, case_number_one_compareCount, case_number_one_swapCount, case_number_one_calculateCount);												// 산술문
	case_number_one_calculateCount++;
	quicksort(a, split + 1, last, case_number_one_compareCount, case_number_one_swapCount, case_number_one_calculateCount);													// 산술문
	// postcondition: a is sorted in ascending order 
	// between first and last inclusive.
}


// cx6-7.cpp
// Code Example 6-7: Partition function (for quicksort, cx6-6.cpp)
int partition(Pharmacy a[], int first, int last, int& case_number_one_compareCount, int& case_number_one_swapCount, int& case_number_one_calculateCount)
{
	int lastSmall(first), i;

	for (i = first + 1; i <= last; i++) {											// 산술문, 비교문
		// loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
		//    a[lastSmall+1]...a[i-1] > a[first]
		case_number_one_compareCount++;
		case_number_one_calculateCount++;
		case_number_one_compareCount++;
		if (a[i].getHold() <= a[first].getHold()) { // key comparison				// 비교문
			++lastSmall;															// 산슬문
			case_number_one_calculateCount++;
			swapElements(a, lastSmall, i);											// swap 횟수
			case_number_one_swapCount++;
		}
	}
	case_number_one_swapCount++;
	swapElements(a, first, lastSmall); // put pivot into correct position			// swap 횟수
	// postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
	//    a[lastSmall+1]...a[last] > a[lastSmall]
	return lastSmall; // this is the final position of the pivot -- the split index
}


void swapElements(Pharmacy a[], int first, int last)
{
	Pharmacy temp = a[first];
	a[first] = a[last];
	a[last] = temp;
}