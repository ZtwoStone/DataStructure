// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"

// #include "LinkTable.h"


void foreachArray(int list[], int size) {
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf(" %d ", list[i]);
	}
	printf("\n");
}

// 选择排序
int *selectSort(int list[], int size) {
	int temp, i, j, maxPosition;
	for (i = 0; i < size; i++) {
		maxPosition = i;
		for (j = i + 1; j < size; j++)
		{
			if (list[j] > list[maxPosition]) {
				maxPosition = j;
			}
		}
		temp = list[i];
		list[i] = list[maxPosition];
		list[maxPosition] = temp;
	}
	return list;
}
// 测试选择排序
void selectSortTest() {
	int *result;
	int list[] = { 8,3,6,5,10,0,2 };
	result = selectSort(list, 7);
	foreachArray(result, 7);
}


void hannuota(int n, int start, int goal, int temp) {
	if (n > 1) {
		hannuota(n - 1, start, temp, goal);
		printf("Move disk %d from %d to %d . \n", n, start, goal);
		hannuota(n - 1, temp, goal, start);
	}
}


int main()
{
	// LinkTablemain();
	// hannuota(5, 1, 3, 2);
	


	return 0;

}