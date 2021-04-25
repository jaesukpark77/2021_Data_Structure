#include <iostream>
#include <string.h>
#include "Pharmacy.h"
#include "selection_sort.h"
#include "Quick_sort.h"
#include "Binary_search.h"
#include<stdlib.h>
using namespace std;

//열 개의 약국 갯수 설정
const int SIZE = 10;

void data_print(Pharmacy data[], int size);

int main()
{
	// main함수에서 10명의 약국을 array로 생성
	// 약국이름, 거리, 마스크 보유잔량, 마스크 도착시간
	// pharmacy_original : 원래 array인데 가장 많은 마스크 보유 잔량을 기준으로 정렬됨
	// pharmacy_info : 이름을 기준으로 정렬 시킬 case
	//원본
	Pharmacy pharmacy_original[10] = {
		Pharmacy("가연약국", 2, 260, 1627),
		Pharmacy("다현약국", 3, 220, 1115),
		Pharmacy("나연약국", 1, 195, 1130),
		Pharmacy("미지약국", 2, 182, 1230),
		Pharmacy("사나약국", 5, 170, 1256),
		Pharmacy("카이약국", 4, 152, 1421),
		Pharmacy("아이약국", 2, 120, 1315),
		Pharmacy("지효약국", 2, 112, 1452),
		Pharmacy("타이약국", 1, 98, 1538),
		Pharmacy("하이약국", 3, 75, 1551),
	};
	//selection sort 적용
	Pharmacy pharmacy_info[10] = {
		Pharmacy("가연약국", 2, 260, 1627),
		Pharmacy("다현약국", 3, 220, 1115),
		Pharmacy("나연약국", 1, 195, 1130),
		Pharmacy("미지약국", 2, 182, 1230),
		Pharmacy("사나약국", 5, 170, 1256),
		Pharmacy("카이약국", 4, 152, 1421),
		Pharmacy("아이약국", 2, 120, 1315),
		Pharmacy("지효약국", 2, 112, 1452),
		Pharmacy("타이약국", 1, 98, 1538),
		Pharmacy("하이약국", 3, 75, 1551),
	};

	cout << "(문제 1) 약국 클래스를 Pharmacy로 정의햐여 구현한다." << endl;
	cout << "********************************************************************************" << endl;
	cout << " " << endl;
	//생성된 화면을 보여준다
	cout << "(문제 2) main 함수에서 열 개의 약국을 array로 생성한다." << endl;
	cout << "<이미 정렬되어 있는 경우>" << endl;
	data_print(pharmacy_info, SIZE);
	cout << "********************************************************************************" << endl;
	cout << " " << endl;
	cout << "(문제 2) selection sort를 이용한 이름 순으로 array 정렬한다" << endl;
	cout << "<이름 순으로 정렬 후 데이터>" << endl;
	//selection sort 
	for (int i = 0; i < SIZE - 1; i++)
	{
		SelectionSort(pharmacy_info, SIZE - i);
	}
	data_print(pharmacy_info, SIZE);
	cout << "********************************************************************************" << endl;
	cout << " " << endl;
	cout << "(문제 3) 특정 이름의 약국을 binary search를 이용하여 구현" << endl;
	//binary search 이용
	cout << "다현약국 찾기" << endl;
	Pharmacy aPharmacy("다현약국", 3, 220, 1115);

	int location1;
	location1 = BinarySearch(pharmacy_info, SIZE, aPharmacy);
	if (location1 == -1)
	{
		printf("탐색 실패 \n");
	}
	else {
		cout << "타겟 저장 인덱스: " << location1;
		cout << " " << endl;
	}

	cout << "구라약국 찾기" << endl;
	Pharmacy zPharmacy("구라약국", 4, 231, 1232);

	int location2;
	location2 = BinarySearch(pharmacy_info, SIZE, zPharmacy);

	if (location2 == -1)
	{
		printf("탐색 실패 \n");
	}
	else {
		cout << "타겟 저장 인덱스: " << location2;
	}

	cout << "********************************************************************************" << endl;
	cout << " " << endl;
	cout << "(문제 4) 마스크 보유 잔량을 기준으로 가장 많은 마스크 잔량을 갖고 있는 순서로 약국을 정렬" << endl;
	//pharmacy_info quicksort 
	int pharmacy_info_compareCount = 0;
	int pharmacy_info_swapCount = 0;
	int pharmacy_info_calculateCount = 0;
	quicksort(pharmacy_info, 0, SIZE - 1, pharmacy_info_compareCount, pharmacy_info_swapCount, pharmacy_info_calculateCount);
	data_print(pharmacy_info, SIZE);

	//pharmacy_original quicksort
	int pharmacy_original_compareCount = 0;
	int pharmacy_original_swapCount = 0;
	int pharmacy_original_calculateCount = 0;
	quicksort(pharmacy_original, 0, SIZE - 1, pharmacy_original_compareCount, pharmacy_original_swapCount, pharmacy_original_calculateCount);
	cout << "********************************************************************************" << endl;
	cout << " " << endl;
	cout << "(문제 5) 실제 연산 갯수를 합산하여 출력" << endl;
	cout << "<pharmacy_info 연산>" << endl;
	cout << "pharmacy_info 비교문 횟수 : " << pharmacy_info_compareCount << endl;
	cout << "pharmacy_info swap 횟수 : " << pharmacy_info_swapCount << endl;
	cout << "pharmacy_info 산술문 횟수 : " << pharmacy_info_calculateCount << endl;
	int pharmacy_info_sum = pharmacy_info_compareCount + pharmacy_info_swapCount + pharmacy_info_calculateCount;
	cout << "pharmacy_info 실제 연산 갯수 : " << pharmacy_info_sum << endl;
	cout << " " << endl;
	cout << "<pharmacy_original 연산>" << endl;
	cout << "pharmacy_original 비교문 횟수 : " << pharmacy_original_compareCount << endl;
	cout << "pharmacy_original swap 횟수: " << pharmacy_original_swapCount << endl;
	cout << "pharmacy_original 산술문 횟수: " << pharmacy_original_calculateCount << endl;
	int pharmacy_original_sum = pharmacy_original_compareCount + pharmacy_original_swapCount + pharmacy_original_calculateCount;
	cout << "pharmacy_original 실제 연산 갯수 : " << pharmacy_original_sum << endl;
	cout << " " << endl;
	cout << "나의 의견 : pharmacy_info는 이름을 기준으로 정렬을 시킬 array이고, pharmacy_original은 원래 array인데 가장 많은 마스크 보유 잔량을 기준으로 정렬되어 있다. quicksort의 시간복잡도에서 최악의 경우는 분할이 1 : n-1로 이루어지는 경우인데, pharmacy_original 경우 1 : n -1로 분할이 되어 pharmacy_info보다 실제 연산 갯수가 많다" << endl;
}

// 화면에 보여준다.
void data_print(Pharmacy data[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "약국이름 : " << data[i].getName() << ", 거리 : " << data[i].getDistance()
			<< ", 마스크 보유잔량 : " << data[i].getHold() << ", 마스크 도착시간 : " << data[i].getArr_time() << endl;
	}
}