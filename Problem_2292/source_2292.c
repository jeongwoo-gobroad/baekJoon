// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No.2292
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
	알고리즘 설명
		Stage 1 : 1
		2 : 6 0
		3 : 12 0, 1
		4 : 18 0, 1
		5 : 24 0, 1, 2
		와 같고
		원리는  1. 스테이지를 알아낸다
				2. Root 6개에서 떨어져있는 거리를 알아낸다
*/

int returnStage(int num, int* startPoint, int* endPoint) {
	int stage = 1;
	int temp = 0;
	do {
		if (num >= *startPoint && num <= *endPoint) {
			break;
		}
		else {
			// temp = *startPoint;
			*startPoint = *endPoint + 1;
			*endPoint = *endPoint + stage * 6;
			stage++;
		}
	} while (1);

	return stage;
}

/*
void returnRoot(int stage, int* rootArr, int startPoint, int endPoint) {
	// 1, 2, 9, 22, 41 -> 1, 1 + 1, 1 + 1 + (1 + 6)
	//   1  7  13  19
	// 공차가 6씩 증가.
	int sttNum = 1;
	int diff = 1;
	const int deltaVal = 6;
	int index = 0;
	// int count = 0;
	// 3rd Stage의 stP = 8, enP = 19

	for (int i = 1; i <= stage; i++) {
		sttNum = sttNum + diff;
		diff += deltaVal;
	}

	for (int i = startPoint; i <= endPoint; i++) {
		if (i == sttNum + ((stage - 1) * index)) {
			rootArr[index] = i;
			index++;
		}
	}

	return;
}

int howFarFromRoot(int num, int* rootArr) {
	int minDiff = 0;

	minDiff = abs(*rootArr - num);

	for (int i = 1; i < 6; i++) {
		if (abs(rootArr[i] - num) < minDiff) {
			minDiff = abs(rootArr[i] - num);
		}
	}
}
*/

int main(void)
{
	int rootArr[6] = { 0 };
	int targetNum = 0;
	int stageNum = 0;
	int addNum = 0;
	int startPoint = 1;
	int endPoint = 1;

	scanf("%d", &targetNum);
	
	stageNum = returnStage(targetNum, &startPoint, &endPoint);

	//returnRoot(stageNum, rootArr, startPoint, endPoint);

	//addNum = howFarFromRoot(targetNum, rootArr);

	printf("%d", stageNum/*+ addNum*/);
	puts("");

	return 0;
}