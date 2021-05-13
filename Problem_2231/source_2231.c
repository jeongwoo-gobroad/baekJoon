// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 2231
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct number {
	int target;
	int tryNum;
	int digit;
	int isGenExist;
} number;

int returnDigit(int num) {
	int digitCnter = 0;
	int divisor = 1;

	do {
		digitCnter++;
		divisor *= 10;
	} while (num % divisor != num);

	return digitCnter;
}

int returnDigitSum(number val) {
	val.digit = returnDigit(val.tryNum);
	int digitSum = 0;
	for (int i = (int)pow(10, val.digit - 1); i >= 1; i /= 10) {
		digitSum += val.tryNum / i;
		val.tryNum %= i;
	}

	return digitSum;
}

number returnMinGenerator(number val) {
	for (int i = 1; i <= val.target; i++) {
		val.tryNum = i;
		if (val.tryNum + returnDigitSum(val) == val.target) {
			val.isGenExist = 1;
			break;
		}
	}

	return val;
}

int main(void)
{
	number ans;

	ans.isGenExist = 0;

	scanf("%d", &ans.target);

	//printf("%d", returnDigitSum(ans));

	ans = returnMinGenerator(ans);

	if (ans.isGenExist != 1) {
		printf("%d\n", ans.isGenExist);
	}
	else {
		printf("%d\n", ans.tryNum);
	}

	return 0;
}