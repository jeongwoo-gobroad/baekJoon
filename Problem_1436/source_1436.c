// KNU CSE 2021****** Jeongwoo Kim
// Baekjoon Problem 1436

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int cnter = 0;

int chkDigit(int num) {
	int divisor = 1;
	int digitCnter = 0;

	do {
		if (num % divisor == num) {
			break;
		}
		else {
			digitCnter++;
			divisor *= 10;
		}
	} while (1);

	return digitCnter;
}

int chkIsFallNum(int* num, int digit) {
	int chunk = 1000;
	int truthVal = 0;
	int divisor = 1;

	for (int i = 1; i <= (int)pow(10, (digit - 1)); i = i * 10) {
		if (*num / i % chunk == 666) {
			truthVal = 1;
			break;
		}
	}

	if (truthVal == 1) {
		cnter++;
		return truthVal;
	}
	else {
		return truthVal;
	}
}

int main(void)
{
	int scanNum = 0;
	int targetNum = 1;
	int digit = 0;

	targetNum = 0;
	cnter = 0;
	scanf("%d", &scanNum);

	while (1) {
		digit = chkDigit(targetNum);

		if (chkIsFallNum(&targetNum, digit) == 1 && cnter == scanNum) {
			break;
		}
		else {
			targetNum++;
		}
	}
	printf("%d\n", targetNum);


	return 0;
}

// Legacy code
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int returnDigit(int* num) {
	int div = 1;
	int digit = 0;
	while (*num % div != *num) {
		digit++;
	}

	return digit;
}

int checkIsDemise(int* num) {
	int divisor = 1000;
	int divisorDigit = 4;
	int numDigit = 0;

	numDigit = returnDigit(num);

	while (numDigit + 2 != divisorDigit) {
		if ((*num % divisor) % (*num % divisor / 1000) == 666) {
			return 1;
		}
		else {
			return 0;
		}
	}

	return 0;
}

int returnDemiseNum(int target) {
	int targetCnter = 0;
	int demiseNum = 665;
	
	do {
		demiseNum++;
		
		if (checkIsDemise(&demiseNum) == 1) {
			targetCnter++;
		}

		if (targetCnter == target) {
			break;
		}
		else {
			continue;
		}
	} while (1);

	return demiseNum;
}

int main(void)
{
	int targetNum = 0;

	scanf("%d", &targetNum);

	printf("%d", returnDemiseNum(targetNum));

	return 0;
}
*/