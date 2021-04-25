#include <iostream>
using namespace std;

#define SIZE 10

int arr[SIZE] = { -1,1,2,3,4,5,6,7,8,9 };
int BinarySearch(int a[], int n, int target);

int main()
{
    int target;
    cout << "배열에서 찾을 정수를 입력하세요: ";
    cin >> target;

    int location;
    location = BinarySearch(arr, SIZE, target);

    if (location == -1)
    {
        printf("탐색 실패 \n");
    }
    else {
        cout << "타겟 저장 인덱스: " << location;
    }
    return 0;
}

int BinarySearch(int a[], int n, int target)
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
