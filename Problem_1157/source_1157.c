// KNU CSE 2021****** Jeongwoo Kim
// BaekJoon Problem No. 1157
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �� ������ �ٽ��� �ֺ� ������ �ٸ��� ���� �� �ִ� ��� ���ĺ��� ������ �����Ǿ� �����Ƿ� Ƚ�� �迭�� ���������μ� ���� Ǯ�� �����ϴ�.
// �׸��� �빮�ڿ� �ҹ��ڸ� �������� ����...


char wordArr[1000001] = { '\0' };

int returnEolVal(char* arr) {
	for (int i = 0; i < 1000001; i++) {
		if (arr[i] == '\0') {
			return i;
		}
	}

	return 0;
}

char returnWord(char* arr, int* eol) {
	int cntArr[52] = { 0 };
	int fmc = 0, mostFreqCnter = 0, mostFreqAddr = 0;
	int isMultiple = 0;

	for (int i = 0; i < *eol; i++) {
		if (wordArr[i] >= 'A' && wordArr[i] <= 'Z') {
			fmc = (int)wordArr[i] - 65;
			(cntArr[fmc])++;
			fmc = 0;
		}
		else if (wordArr[i] >= 'a' && wordArr[i] <= 'z') {
			fmc = (int)wordArr[i] - 71;
			(cntArr[fmc])++;
			fmc = 0;
		} 
	}

	mostFreqCnter = cntArr[0];
	mostFreqAddr = 0;

	for (int i = 1; i < 52; i++) {
		if (cntArr[i] > mostFreqCnter && cntArr[i] != 0) {
			mostFreqAddr = i;
			mostFreqCnter = cntArr[i];
		}
		else if (cntArr[i] == mostFreqCnter && cntArr[i] != 0) {
			isMultiple++;
			break;
		}
	}

	if (isMultiple != 0) {
		return '?';
	}
	else {
		if (mostFreqAddr >= 0 && mostFreqAddr <= 25) {
			return (char)(mostFreqAddr + 65);
		}
		else {
			return (char)(mostFreqAddr + 71);
		}
	}
}

void capitalizeLetter(char* ch) {
	if (*ch >= 'A' && *ch <= 'Z') {
		return;
	}
	else {
		*ch = (char)((int)(*ch) - 32);
		return;
	}
}

int main(void)
{
	int eolPtr;
	char mostFreqentLetter = '\0';

	scanf("%s", wordArr);

	eolPtr = returnEolVal(wordArr);

	mostFreqentLetter = returnWord(wordArr, &eolPtr);

	if (mostFreqentLetter == '?') {
		printf("%c\n", mostFreqentLetter);
	}
	else {
		capitalizeLetter(&mostFreqentLetter);

		printf("%c\n", mostFreqentLetter);
	}

	return 0;
}