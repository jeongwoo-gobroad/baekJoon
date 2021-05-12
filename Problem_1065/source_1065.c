// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 1065
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int returnDigit(int num) {
	int digit = 0;
	int digitCnter = 1;
	while (num % digitCnter != num) {
		digit++;
		digitCnter *= 10;
	}

	return digit;
}

int isHansu(int num, int digit) {
	int diff = 0;
	int tmp = 0;
	int chkTrue = 0;
	if (digit == 1 || digit == 2) return 1;
	else {
		diff = (num / (int)pow(10, digit - 1)) - (num / (int)pow(10, digit - 2) % 10); // 공차를 구하는 알고리즘.
		for (int i = (int)pow(10, digit - 2); i > 1; i /= 10) {
			tmp = (num / i % 10) - (num / (i / 10) % 10); // n-2자리의 공차 여부를 구하는 알고리즘.
			if (tmp == diff) {
				chkTrue++;
			}
			tmp = 0;
		}
		if (chkTrue == digit - 2) { // 첫째/둘째항은 검사에서 제외하므로 digit - 2.
			return 1;
		}
		else {
			return 0;
		}
	}
}

int main(void)
{
	int targetNum = 0;
	int cnter = 1;
	int digit = 0;
	int truthCnter = 0;

	scanf("%d", &targetNum);

	while (1) {
		if (cnter == targetNum + 1) break;
		else {
			digit = returnDigit(cnter);
			if (isHansu(cnter, digit) == 1) {
				truthCnter++;
			}
			cnter++;
		}
	}

	printf("%d\n", truthCnter);

	return 0;
}