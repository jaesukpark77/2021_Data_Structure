#include <iostream>
#include "Pharmacy.h"

using namespace std;

int partition(Pharmacy a[], int first, int last, int& case_number_one_compareCount, int& case_number_one_swapCount, int& case_number_one_calculateCount);
void quicksort(Pharmacy a[], int first, int last, int& case_number_one_compareCount, int& case_number_one_swapCount, int& case_number_one_calculateCount);
void swapElements(Pharmacy a[], int first, int last);