// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 2108
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
// 입력받는 인자의 개수는 홀수개이다.
// 최빈값이 여러개일 경우 두번째로 작은 값을 출력한다.
/*
	최빈값이 여러개일 경우 두번째로 작은 값을 인식하는 알고리즘
	1122223333444455
	1. 최빈값의 항목을 저장하는 변수를 3개 만든다.
	2. 순차적으로 저장한다.
*/

int numArr[500000] = { 0 };

int sortArr(int* arr, int *numCnter) { // 버블정렬
	int isSort = 0;
	int temp = 0;
	do {
		isSort = 0;
		for (int i = 0; i < *numCnter; i++) {
			if (i == *numCnter - 1) {
				if (*arr > arr[i]) {
					temp = *arr;
					*arr = arr[i];
					arr[i] = temp;
				}
				else {
					isSort++;
				}
			}
			else {
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
				else {
					isSort++;
				}
			}
		}
	} while (isSort != *numCnter);

	return 0;
}

int arithMean(int* arr, int* numCnter) { // 산술평균
	int sum = 0;
	for (int i = 0; i < *numCnter; i++) {
		sum += arr[i];
	}

	if (sum < 0) {
		return ((float)sum / *numCnter) - 0.5;
	}
	else {
		return ((float)sum / *numCnter) + 0.5;
	}
}

int arithMedian(int* arr, int *numCnter) { // 중앙값
	return arr[(int)(*numCnter / 2)];
}

int arithMode(int* arr, int* numCnter) { // 최빈값로직이 문제임....
	int tempModeCnter = 0; // 
	int modeCnter = 0;
	int chkVal = 0;
	int tempModeVal = 0;
	int modeVal01 = 0, modeVal02 = 0;

	for (int i = 0; i < *numCnter - 1; i++) {
		for (int j = i + 1; j < *numCnter; j++) {
			if (arr[i] == arr[j]) {
				tempModeCnter++;
			}
		}
		if (tempModeCnter > modeCnter) {
			modeCnter = tempModeCnter;
			modeVal01 = arr[i];
		}
		else if (tempModeCnter == modeCnter) {
			if (chkVal == 0) {
				modeVal02 = arr[i];
				chkVal++;
			}
			else {
				modeVal01 = modeVal02;
				modeVal02 = arr[i];
			}
		}
		modeCnter = 0;
	}

	return modeVal01;
}

int arithMaxMinDiff(int* arr, int* numCnter) { // 범위
	return arr[*numCnter - 1] - arr[0];
}

int main(void)
{
	int cnter = 0;

	scanf("%d", &cnter);

	for (int i = 0; i < cnter; i++) {
		scanf("%d", &numArr[i]);
	}

	sortArr(numArr, &cnter);

	printf("%d\n", arithMean(numArr, &cnter));
	printf("%d\n", arithMedian(numArr, &cnter));
	printf("%d\n", arithMode(numArr, &cnter));
	printf("%d\n", arithMaxMinDiff(numArr, &cnter));

	return 0;
}