// KNU CSE 2021****** Jeongwoo Kim
// specialSort
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

# include <stdio.h>
# define MAX_SIZE 9
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do {
			low++; // low는 left+1 에서 시작
		} while (low <= right && list[low] < pivot);

		do {
			high--; //high는 right 에서 시작
		} while (high >= left && list[high] > pivot);

		if (low < high) {
			SWAP(list[low], list[high], temp);
		}
	} while (low < high);

	SWAP(list[left], list[high], temp);

	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right); // q: 피벗의 위치
		printf("피벗의 위치는 %d이며, 값은 %d입니다.\n", q, list[q]);

		quick_sort(list, left, q - 1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
		quick_sort(list, q + 1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
	}

	return;
}

int main(void) {
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };

	printf("배열 첨자: \n");
	printf("0|1|2|3|4|5|6|7|8\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	puts("");
	puts("");

	quick_sort(list, 0, n - 1);

	puts("");

	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	puts("");

	return 0;
}


/*
int sortBubbleArr(int* arr, int* numCnter) { // 버블정렬
	int isSort = 0;
	int temp = 0;
	do {
		isSort = 0;
		for (int i = 0; i < *numCnter; i++) {
			if (i == *numCnter - 1) {
				if (*arr > arr[i]) {
					temp = *arr;
					*arr = arr[i];
					arr[i] = temp;
					printf("%d번 자리의 %d를 %d번 자리의 %d와 교체\n", 0, arr[0], i, arr[i]);
				}
				else {
					isSort++;
				}
			}
			else {
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					printf("%d번 자리의 %d를 %d번 자리의 %d와 교체\n", i, arr[i], i + 1, arr[i + 1]);
				}
				else {
					isSort++;
				}
			}
		}
	} while (isSort != *numCnter);

	return 0;
}

int quickSortArr(int* arr, int left, int right) {
	int flag = 0;

	flag = *arr;
	printf("%d를 Pivot화 합니다.\n", flag);

	for (int i = 0; i < 8; i++) {

	}
	

}

int main(void)
{
	int array[9] = { 3, 2, 10, 7, 24, 9, 47, -6, 2 };
	int cnter = 10;

	for (int i = 0; i < 9; i++) {
		printf("%d ", array[i]);
	}
	puts("");
	puts("");

	// sortBubbleArr(array, &cnter);

	quickSortArr(array, 0, 8);

	puts("");

	for (int i = 0; i < 9; i++) {
		printf("%d ", array[i]);
	}
	puts("");

	return 0;
}

*/

/*
int sortArr(int* arr, int* numCnter) { // 버블정렬
	int isSort = 0;
	int temp = 0;
	do {
		isSort = 0;
		for (int i = 0; i < *numCnter; i++) {
			if (i == *numCnter - 1) {
				if (*arr > arr[i]) {
					temp = *arr;
					*arr = arr[i];
					arr[i] = temp;
					printf("%d번 자리의 %d를 %d번 자리의 %d와 교체\n", 0, arr[0], i, arr[i]);
				}
				else {
					isSort++;
				}
			}
			else {
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					printf("%d번 자리의 %d를 %d번 자리의 %d와 교체\n", i, arr[i], i + 1, arr[i + 1]);
				}
				else {
					isSort++;
				}
			}
		}
	} while (isSort != *numCnter);

	return 0;
}

int main(void)
{
	int array[10] = { 3, 2, 10, 7, 24, 88, 9, 47, -6, 2 };
	int cnter = 10;

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	puts("");
	puts("");

	sortArr(array, &cnter);

	puts("");

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	puts("");

	return 0;
}
*/