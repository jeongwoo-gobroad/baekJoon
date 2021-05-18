// KNU CSE 2021****** Jeongwoo Kim
// Baekjoon Problem No. 1712
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef unsigned long u_int;

typedef struct management {
	u_int fixedCost;
	u_int productionCost;
	u_int resaleCost;
	int isProfit;
} manage;

void isProfitable(manage* target) {
	int tempVal1 = target->resaleCost - (target->fixedCost + target->productionCost);
	int tempVal2 = target->resaleCost * 2 - (target->fixedCost + target->productionCost * 2);

	if (tempVal1 > tempVal2) {
		target->isProfit = -1;
	}
	else {
		target->isProfit = 0;
	}

	return;
}

manage returnBreakEvenPoint(manage target) {
	// u_int tempVal1 = 0, tempVal2 = 0; // 손실이 계속해서 늘어나면 손익분기점이 존재하지 않는다는것을 밝히기 위해 이전실현이익과 현실현이익을 저장.
	/*
	register int cnter = 0;
	target.isProfit = 0;

	while (!((u_int)((u_int)target.resaleCost * (u_int)target.isProfit) > (u_int)((u_int)target.fixedCost + (u_int)target.productionCost * (u_int)target.isProfit))) {
		if ((tempVal1 > tempVal2) && (cnter > 1)) {
			target.isProfit = -1;
			break;
		}
		else {
			target.isProfit++;
			if (!(cnter == 0 || cnter == 1)) {
				tempVal1 = tempVal2;
				tempVal2 = (target.resaleCost * target.isProfit) - (target.fixedCost + target.productionCost * target.isProfit);
			}
			else if (cnter == 0){
				tempVal1 = (target.resaleCost * target.isProfit) - (target.fixedCost + target.productionCost * target.isProfit);
				cnter++;
			}
			else {
				tempVal2 = (target.resaleCost * target.isProfit) - (target.fixedCost + target.productionCost * target.isProfit);
				cnter++;
			}
		}
	}
	*/ // 이 코드의 문제점은 증가연산을 통해 일일이 조건검사를 한다는것. 따라서 일차부등식을 통한 해법으로 접근해야한다.
	 
	// 1. 생산할 때 마다 손실이 증가하는지를 검사한다.
	isProfitable(&target);

	if (target.isProfit == -1) {
		return target;
	}

	// 2. 일차부등식 i > A / (C-B)를 이용해 최소판매량을 검사한다.
	else {
		target.isProfit = target.fixedCost / (target.resaleCost - target.productionCost) + 0.5;

		if (target.resaleCost * target.isProfit == target.fixedCost + target.productionCost * target.isProfit) {
			target.isProfit += 1; // 손익분기점을 "넘어"야 하므로
		}
	}

	/*
		이 문제의 교훈: 특정한 성취값을 찾기 위해 정말 피치 못할 경우에만 반복문을 써라. 반복문은 시간 낭비 + 카운터 변수 낭비이다.
		산술식이나 점화식이 존재할 경우에는 해당 식을 활용하라.
	*/

	return target;
}

int main(void)
{
	manage target;
	manage* ptarget = &target;

	scanf("%lu %lu %lu", &ptarget->fixedCost, &ptarget->productionCost, &ptarget->resaleCost);

	target = returnBreakEvenPoint(target);

	printf("%d\n", ptarget->isProfit);

	return 0;
}