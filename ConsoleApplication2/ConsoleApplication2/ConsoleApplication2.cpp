// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include <string.h>
#include <stdlib.h>
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

// ѡ������
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
// ˳������
void shunxuSort() {
	int  list[6] = { 111,222,333,444,555,666 };
	int target = 222;
	int position = -1;
	for (position = 0; list[position] != target; position++);
	printf("%d\n", position);

}

// ���ַ�����  ǰ�᣺�����Ѿ�����
int BinarySort(int List[],int size , int target) {
	int left, right, mid;

	left = 1;
	right = size;
	while (left <= right) {
		mid = (left + right) / 2;
		if (List[mid] > target) {
			right = mid - 1;
		}
		else if (target > List[mid]) {
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

// ����ѡ������
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

// ����һ���ַ�����������������õݹ�
void StringReversePrint()
{
	char a;
	scanf_s("%c", &a);
	// �����Ϊ# ��������
	if (a != '#') StringReversePrint();
	// ������#������ʱ�򣬵ݹ����η��ز����
	if (a != '#') printf( "%c" , a);
}


int main()
{
	// LinkTablemain();
	// hannuota(5, 1, 3, 2);
	
	// shunxuSort();
	/*
	int list[8] = { 1,5,8,9,15,22,45,56 };
	int i = BinarySort(list, 8, 22);
	printf("%d\n", i);
	*/

	StringReversePrint();

	return 0;

}