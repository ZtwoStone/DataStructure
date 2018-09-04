// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include "malloc.h"

// #include "LinkTable.h"

#include "RadixSort.h"


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


// 顺序排序
void shunxuSort() {
	int  list[6] = { 111,222,333,444,555,666 };
	int target = 222;
	int position = -1;
	for (position = 0; list[position] != target; position++);
	printf("%d\n", position);

}


// 二分法排序  前提：必须已经排序
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

// 交换值
void Swap(int *a, int *b) {
	int t = *a;
	*a = *b; 
	*b = t;
}

// 堆排序  
// 将数组调整为最大堆 1
void PercDown(int A[], int p, int N) {
	int Parent, Child;
	int X;

	X = A[p];
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ( (Child != N - 1) && (A[Child] < A[Child + 1])  ) {
			Child++;
		}
		if (X >= A[Child]) { break; }
		else {
			A[Parent] = A[Child];
		}

	}
	A[Parent] = X;
}

// 堆排序  2
void HeapSort(int A[], int N) {
	int i;
	for (i = N / 2 - 1; i >= 0; i--) {
		PercDown(A, i, N);
	}
	foreachArray(A, N);
	for (i = N - 1; i > 0; i--) {
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

// 冒泡排序
void BubbleSort(int a[], int n) {
	int p, i;
	bool flag;

	for (p = n - 1; p >= 0; p--) {
		flag = false;
		for (i = 0; i < p; i++) {
			if (a[i] > a[i + 1]) {
				Swap(&a[i], &a[i + 1]);
				flag = true;
			}
		}
		if (flag == false) break;   //没有交换说明全部已排序
	}
}

// 冒泡排序 我的写法
void maopaoSort(int a[], int n) {
	int i, y;
	for (i = n - 1; i >= 0; i--) {
		for (y = 0; y < i; y++) {
			if (a[y ] > a[y+1]) {
				int tmp;
				tmp = a[y];
				a[y] = a[y + 1];
				a[y + 1] = tmp;
			}
		}
	}
}


// 插入排序
void InsertSort(int A[], int N) {
	int P, i;
	int tmp;

	for (P = 1; P < N; P++) {
		tmp = A[P];
		for (i = P; i>0 && A[i - 1] > tmp; i--) {
			A[i] = A[i - 1];
		}
		A[i] = tmp;
	}
}

// 希尔排序
// 分段排序，将数组按照一定长度分开排序
// a= {1,2,3,4,5,6,7,8}
// 分量为3；则依次排序 a[0]和a[3] a[2]和a[4]
// 继续分量为下一个继续执行
void ShellSort(int a[], int n) {
	int si, d, p, i;
	int tmp;

	int sw[] = { 929,505,209,108,41,19,5,1,0 };
	
	for (si = 0; sw[si] >= n; si++)
		;
	
	for (d = sw[si]; d > 0; d = sw[++si]) {
		for (p = d; p < n; p++) {  // 插入排序
			tmp = a[p];
			for (i = p; i >= d&& a[i - d] > tmp; i -= d) {
				a[i] = a[i - d];
			}
			a[i] = tmp;
		}
	}
}

/*
	快速排序

*/

// 查找基准值
int Median3(int a[], int left, int right) {
	int center = (left + right) / 2;
	if (a[left] > a[right]) {
		Swap(&a[left], &a[right]);
	}
	if (a[left] > a[center]) {
		Swap(&a[left], &a[center]);
	}
	if (a[center] > a[right]) {
		Swap(&a[center], &a[right]);
	}
	// 此时 a[left]<=a[center]<=a[right]
	Swap(&a[center], &a[right - 1]);
	return a[right - 1];
}

// 快速排序 核心
void  QSort(int a[], int left, int right) {
	int pivot;			// 基准值
	int cutoff = 3;			// 小于多少个数的时候使用快速排序
	int low;			// 左边遍历的位置
	int height;			// 右边遍历的位置

	if (cutoff <= right - left) {
		pivot = Median3(a, left, right);
		low = left;
		height = right - 1;
		while (1) {
			while (a[++low] < pivot);
			while (a[--height] > pivot);
			if (low < height) {
				Swap(&a[low], &a[height]);
			}
			else {
				break;
			}
		}
		Swap(&a[low], &a[right - 1]);
		QSort(a, left, low - 1);
		QSort(a, low + 1, right);
	}
	else {
		InsertSort(a + left, right - left + 1);
	}
}

void QuickSort(int a[], int n) {
	QSort(a, 0, n - 1);
}


/*
	归并排序
*/

// 合并两个序列
// l 左边起始位置   r右边起始位置  rightEnd右边重点位置
void merge(int a[], int tmpA[], int leftIndex, int rightIndex, int rightEnd) {
	// 将有序的 a[lleftIndex] - a[rightIndex-1] 和 a[rrightIndex] - a[rightEnd] 归并成一个有序序列
	int leftEnd, size, tmp;
	int i;

	leftEnd = rightIndex - 1;
	tmp = leftIndex;
	size = rightEnd - leftIndex + 1;  // 两个序列的总长度

	
	while (leftIndex <= leftEnd && rightIndex <= rightEnd) {
		if (a[leftIndex] <= a[rightIndex]) {
			tmpA[tmp++] = a[leftIndex++];
		}
		else {
			tmpA[tmp++] = a[rightIndex++];
		}
	}

	while (leftIndex <= leftEnd) {
		tmpA[tmp++] = a[leftIndex++];
	}
	while (rightIndex <= rightEnd) {
		tmpA[tmp++] = a[rightIndex++];
	}

	// 将排好序并合并好的数组赋值回原数组a
	for (i = 0; i < size; i++, rightEnd--) {
		a[rightEnd] = tmpA[rightEnd];
	}

}

// 递归排序 核心函数  拆分成不同的数组
void Msort(int a[], int tmpA[], int l, int rightEnd) {
	int center;

	if (l < rightEnd) {
		center = (l + rightEnd) / 2;
		Msort(a, tmpA, l, center);
		Msort(a, tmpA, center + 1, rightEnd);
		merge(a, tmpA, l, center + 1, rightEnd);
	}
}

// 递归排序入口
void MergeSort(int a[], int n) {
	int *tmpA;
	tmpA = (int *)malloc(n * sizeof(int));

	if (tmpA != NULL) {
		Msort(a, tmpA, 0, n - 1);
	}
	else {
		printf("空间不足");
	}

}


// 测试选择排序
void selectSortTest() {
	int *result;
	int list[] = { 8,3,6,5,10,0,2 };
	result = selectSort(list, 7);
	foreachArray(result, 7);
}

// 测试堆排序
void testHeapSort() {
	int *result;
	int list[] = { 8,3,6,5,10,0,2 };
	HeapSort(list, 7);
	foreachArray(list, 7);
}

// 测试插入排序
void testInsertSort() {
	int list[] = { 8,3,6,5,10,0,2 };
	foreachArray(list, 7);
	InsertSort(list, 7);
	foreachArray(list, 7);
}

// 测试希尔排序
void testShellSort() {
	int list[] = { 8,3,6,5,10,0,2 };
	foreachArray(list, 7);
	ShellSort(list, 7);
	foreachArray(list, 7);
}


// 测试冒泡排序
void testBubbleSort() {
	int list[] = { 8,3,6,5,10,0,2 };
	foreachArray(list, 7);
	 QuickSort(list, 7);
	// maopaoSort(list, 7);
	foreachArray(list, 7);
}

// 测试快速排序
void testQuickSort() {
	int list[] = { 8,3,6,5,10,0,2,4,1,7 };
	foreachArray(list, 10);
	QuickSort(list, 10);
	foreachArray(list, 10);
}

// 测试归并排序
void testMergeSort() {
	int list[] = { 8,3,6,5,10,0,2,4,1,7 };
	foreachArray(list, 10);
	MergeSort(list, 10);
	foreachArray(list, 10);
}

void testRadixSort() {
	int list[] = { 108,35,956,15,104,80,29,41,140,7 };
	foreachArray(list, 10);
	LSDRadixSort(list, 10);
	foreachArray(list, 10);
	
}

//   汉诺塔
void hannuota(int n, int start, int goal, int temp) {
	if (n > 1) {
		hannuota(n - 1, start, temp, goal);
		printf("Move disk %d from %d to %d . \n", n, start, goal);
		hannuota(n - 1, temp, goal, start);
	}
}


// 输入一个字符串，并反向输出，用递归
void StringReversePrint()
{
	char a;
	scanf_s("%c", &a);
	// 如果不为# 继续输入
	if (a != '#') StringReversePrint();
	// 当输入#结束的时候，递归依次返回并输出
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

	// StringReversePrint();
	// testHeapSort();
	// testInsertSort();
	// testShellSort();
	// testBubbleSort();
	// testQuickSort();
	testRadixSort();
	return 0;

}