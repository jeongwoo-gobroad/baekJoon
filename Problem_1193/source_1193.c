// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 1157
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
분자 numerator
1
1 2
3 2 1
1 2 3 4

분모 denominator
1 // 1
2 1 // 2 3
1 2 3 // 4 6
4 3 2 1 // 7 10

따라서 어떤 수가 몇번째 stage의 몇번째 index인지가 중요하다.
*/

typedef struct fraction {
	int stage;
	int index;
} fraction;

fraction returnInfo(int num) { // 특정 수의 stage와 index를 반환합니다.
	fraction target;
	target.stage = 1;
	target.index = 0;
	int startPoint = 1;
	int endPoint = 1;
	int cnter = 1;

	while (1) {
		if (num >= startPoint && num <= endPoint) {
			break;
		}
		startPoint += cnter;
		endPoint += cnter + 1;
		cnter++;
		target.stage++;
	}

	for (int i = startPoint; i <= endPoint; i++) {
		if (i == num) {
			break;
		}
		target.index++;
	}

	return target;
}

int returnNumerator(fraction num) {
	int numerator = 1;

	if (num.stage % 2 == 0) {
		for (int i = 0; i < num.index; i++) {
			numerator++;
		}
	}
	else {
		numerator = num.stage;
		for (int i = 0; i < num.index; i++) {
			numerator--;
		}
	}

	return numerator;
}

int returnDenominator(fraction num) {
	int denominator = 1;

	if (num.stage % 2 == 0) {
		denominator = num.stage;
		for (int i = 0; i < num.index; i++) {
			denominator--;
		}
	}
	else {
		for (int i = 0; i < num.index; i++) {
			denominator++;
		}
	}

	return denominator;
}

int main(void)
{
	int num;
	fraction numInfo;

	scanf("%d", &num);

	numInfo = returnInfo(num);

	printf("%d/%d", returnNumerator(numInfo), returnDenominator(numInfo));

	//x = returnInfo(num);

	//printf("%d %d", x.stage, x.index);

	return 0;
}