// KNU CSE 2021****** Jeongwoo Kim
// 백준 2750번 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sort(int* arr, int arrSize) {
	int isSort = 0;
	int temp = 0;

	while (1) {
		isSort = 0;
		for (int i = 0; i < arrSize; i++) {
			if ((i + 1) == arrSize) {
				if (*(arr) > *(arr + i)) {
					temp = *arr;
					*arr = *(arr + i);
					*(arr + i) = temp;
				}
				else {
					isSort++;
				}
			}
			else {
				if (*(arr + i) > *(arr + i + 1)) {
					temp = *(arr + i);
					*(arr + i) = *(arr + i + 1);
					*(arr + i + 1) = temp;
				}
				else {
					isSort++;
				}
			}
		}
		if (isSort == arrSize) {
			break;
		}
		else {
			continue;
		}
	}

	return 0;
}

int main(void)
{
	int arr[1000] = { 0 };
	int cnter = 0;

	scanf("%d", &cnter);

	for (int i = 0; i < cnter; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, cnter);

	for (int i = 0; i < cnter; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}