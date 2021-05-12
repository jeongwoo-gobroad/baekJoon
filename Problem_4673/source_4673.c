// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 4673
#include <stdio.h>
#include <math.h>

int returnDigit(int num) {
	int cnter = 0;
	int chunk = 1;

	do {
		cnter++;
		chunk *= 10;
	} while (num % chunk != num);

	return cnter;
}

int returnSelfVal(int val, int num, int digit) {
	int digitSum = 0;

	for (int i = (int)pow(10, (digit - 1)); i >= 1; i /= 10) {
		if (num == 0) break;

		digitSum += num / i;
		num %=  i;
	}

	return (digitSum + val);
}

int isSelfNum(int num) {

	for (int i = 1; i < num; i++) {
		if (returnSelfVal(i, i, returnDigit(i)) == num) {
			return 1;
		}
	}

	return 0;
}

int main(void)
{
	int inum = 1;

	for (int i = 0; i < 10000; i++) {
		if (isSelfNum(inum) == 0) {
			printf("%d", inum);
			puts("");
		}
		inum++;
	}

	return 0;
}