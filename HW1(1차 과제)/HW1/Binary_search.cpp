#include "Binary_search.h"

int BinarySearch(Pharmacy a[], int n, Pharmacy target)
{
    // Precondition: array a is sorted in ascending order from a[0] to a[n-1]
    int first(0);
    int last(n - 1);
    int mid;
    while (first <= last) {
        // Invariant: if target in a, then a[first] <= target <= a[last]
        mid = (first + last) / 2;
        if (target == a[mid])
            return mid;
        else if (target < a[mid])
            last = mid - 1;
        else // must be that target > a[mid]
            first = mid + 1;
    }
    return -1; //use -1 to indicate item not found
}