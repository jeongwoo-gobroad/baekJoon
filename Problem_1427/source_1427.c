// KNU CSE 2021****** Jeongwoo Kim
// 백준 1427번 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int returnDigit(int num) {
	int cnter = 0;

	for (int i = 1; i <= 1000000000; i *= 10) {
		if ((num % i) != num) {
			cnter++;
		}
		else {
			break;
		}
	}
	return cnter;
}

void digittoArr(int num, int digit, int* arr) {
	int div = 10;

	for (int i = 0; i < digit; i++) {
		arr[i] = num % div;
		num /= div;
	}

	return;
}

void sortDigit(int* arr, int digit) {
	int cnter = 0;
	int temp = 0;

	while (1) {
		cnter = 0;
		for (int i = 0; i < digit; i++) {
			if ((i + 1) == digit) {
				if (arr[0] < arr[i]) {
					temp = arr[0];
					arr[0] = arr[i];
					arr[i] = temp;
				}
				else {
					cnter++;
				}
			}
			else {
				if (arr[i] < arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
				else {
					cnter++;
				}
			}
		}
		
		if (cnter == digit) {
			break;
		}
		else {
			continue;
		}
	}

	return;
}

int main(void)
{
	int digitArr[10] = { 0 };
	int targetNum = 0;
	int digitCnter = 0;

	scanf("%d", &targetNum);

	digitCnter = returnDigit(targetNum);

	digittoArr(targetNum, digitCnter, digitArr);

	sortDigit(digitArr, digitCnter);

	for (int i = 0; i < digitCnter; i++) {
		printf("%d", digitArr[i]);
	}
	puts("");

	return 0;
}