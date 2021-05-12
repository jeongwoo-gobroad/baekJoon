// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 10870
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int targetNum = 0;

int recursiveFib(int n1, int n2) {
	if (targetNum == 0) {
		return n1;
	}
	else {
		targetNum--;
		return recursiveFib(n2, n1 + n2);
	}
}

int main(void)
{
	scanf("%d", &targetNum);

	printf("%d\n", recursiveFib(0, 1));

	return 0;
}