// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 1018
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
�˰��� ����
[50][50]¥�� ���� �迭�� ���� ��
�Էµ� ������ �ƴ϶�� ���� �迭�� ���� ä���.
�״��� 8*8¥�� ��ĵ �Լ��� ���� �ٲپ�� �ϴ� �ڸ��� �˻��ϰ�
���� ���� ���� �����Ѵ�.

�����ؾ� �� �Լ�
1. 8*8¥�� ��ĵ�Լ�
2. 8*8¥�� ù ������ W�� �Ͽ� ��ȭ���Ѿ� �� Ƚ���� �����ϴ� �Լ�
3. 8*8¥�� ù ������ B�� �Ͽ� ��ȭ���Ѿ� �� Ƚ���� �����ϴ� �Լ�
4. �񱳴���� �����迭[8][8]
*/

int main(void)
{
	char board[50][50] = { '\0' };
	int minCnter = 0;
	int x_board = 0, y_board = 0;

	scanf("%d %d", &x_board, &y_board);

	for (int i = 0; i < x_board; i++) {
		for (int j = 0; j < y_board; j++) {
			scanf("%c", &board[i][j]);
			getchar();
		}
	}

	for (int i = 0; i < x_board; i++) {
		for (int j = 0; j < y_board; j++) {
			printf("%c ", board[i][j]);
		}
		puts("");
	}

	return 0;
}