// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 1018
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
알고리즘 설명
[50][50]짜리 문자 배열을 생성 후
입력된 공간이 아니라면 문자 배열에 널을 채운다.
그다음 8*8짜리 스캔 함수를 통해 바꾸어야 하는 자리를 검사하고
가장 작은 수를 리턴한다.

구현해야 할 함수
1. 8*8짜리 스캔함수
2. 8*8짜리 첫 시작을 W로 하여 변화시켜야 할 횟수를 점검하는 함수
3. 8*8짜리 첫 시작을 B로 하여 변화시켜야 할 횟수를 점검하는 함수
4. 비교대상의 전역배열[8][8]
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