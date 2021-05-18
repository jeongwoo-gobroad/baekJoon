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
	// u_int tempVal1 = 0, tempVal2 = 0; // �ս��� ����ؼ� �þ�� ���ͺб����� �������� �ʴ´ٴ°��� ������ ���� �����������Ͱ� ������������ ����.
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
	*/ // �� �ڵ��� �������� ���������� ���� ������ ���ǰ˻縦 �Ѵٴ°�. ���� �����ε���� ���� �ع����� �����ؾ��Ѵ�.
	 
	// 1. ������ �� ���� �ս��� �����ϴ����� �˻��Ѵ�.
	isProfitable(&target);

	if (target.isProfit == -1) {
		return target;
	}

	// 2. �����ε�� i > A / (C-B)�� �̿��� �ּ��Ǹŷ��� �˻��Ѵ�.
	else {
		target.isProfit = target.fixedCost / (target.resaleCost - target.productionCost) + 0.5;

		if (target.resaleCost * target.isProfit == target.fixedCost + target.productionCost * target.isProfit) {
			target.isProfit += 1; // ���ͺб����� "�Ѿ�"�� �ϹǷ�
		}
	}

	/*
		�� ������ ����: Ư���� ���밪�� ã�� ���� ���� ��ġ ���� ��쿡�� �ݺ����� ���. �ݺ����� �ð� ���� + ī���� ���� �����̴�.
		������̳� ��ȭ���� ������ ��쿡�� �ش� ���� Ȱ���϶�.
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