// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
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

// ����ֵ
void Swap(int *a, int *b) {
	int t = *a;
	*a = *b; 
	*b = t;
}

// ������  
// ���������Ϊ���� 1
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

// ������  2
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

// ð������
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
		if (flag == false) break;   //û�н���˵��ȫ��������
	}
}

// ð������ �ҵ�д��
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


// ��������
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

// ϣ������
// �ֶ����򣬽����鰴��һ�����ȷֿ�����
// a= {1,2,3,4,5,6,7,8}
// ����Ϊ3������������ a[0]��a[3] a[2]��a[4]
// ��������Ϊ��һ������ִ��
void ShellSort(int a[], int n) {
	int si, d, p, i;
	int tmp;

	int sw[] = { 929,505,209,108,41,19,5,1,0 };
	
	for (si = 0; sw[si] >= n; si++)
		;
	
	for (d = sw[si]; d > 0; d = sw[++si]) {
		for (p = d; p < n; p++) {  // ��������
			tmp = a[p];
			for (i = p; i >= d&& a[i - d] > tmp; i -= d) {
				a[i] = a[i - d];
			}
			a[i] = tmp;
		}
	}
}

/*
	��������

*/

// ���һ�׼ֵ
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
	// ��ʱ a[left]<=a[center]<=a[right]
	Swap(&a[center], &a[right - 1]);
	return a[right - 1];
}

// �������� ����
void  QSort(int a[], int left, int right) {
	int pivot;			// ��׼ֵ
	int cutoff = 3;			// С�ڶ��ٸ�����ʱ��ʹ�ÿ�������
	int low;			// ��߱�����λ��
	int height;			// �ұ߱�����λ��

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
	�鲢����
*/

// �ϲ���������
// l �����ʼλ��   r�ұ���ʼλ��  rightEnd�ұ��ص�λ��
void merge(int a[], int tmpA[], int leftIndex, int rightIndex, int rightEnd) {
	// ������� a[lleftIndex] - a[rightIndex-1] �� a[rrightIndex] - a[rightEnd] �鲢��һ����������
	int leftEnd, size, tmp;
	int i;

	leftEnd = rightIndex - 1;
	tmp = leftIndex;
	size = rightEnd - leftIndex + 1;  // �������е��ܳ���

	
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

	// ���ź��򲢺ϲ��õ����鸳ֵ��ԭ����a
	for (i = 0; i < size; i++, rightEnd--) {
		a[rightEnd] = tmpA[rightEnd];
	}

}

// �ݹ����� ���ĺ���  ��ֳɲ�ͬ������
void Msort(int a[], int tmpA[], int l, int rightEnd) {
	int center;

	if (l < rightEnd) {
		center = (l + rightEnd) / 2;
		Msort(a, tmpA, l, center);
		Msort(a, tmpA, center + 1, rightEnd);
		merge(a, tmpA, l, center + 1, rightEnd);
	}
}

// �ݹ��������
void MergeSort(int a[], int n) {
	int *tmpA;
	tmpA = (int *)malloc(n * sizeof(int));

	if (tmpA != NULL) {
		Msort(a, tmpA, 0, n - 1);
	}
	else {
		printf("�ռ䲻��");
	}

}


// ����ѡ������
void selectSortTest() {
	int *result;
	int list[] = { 8,3,6,5,10,0,2 };
	result = selectSort(list, 7);
	foreachArray(result, 7);
}

// ���Զ�����
void testHeapSort() {
	int *result;
	int list[] = { 8,3,6,5,10,0,2 };
	HeapSort(list, 7);
	foreachArray(list, 7);
}

// ���Բ�������
void testInsertSort() {
	int list[] = { 8,3,6,5,10,0,2 };
	foreachArray(list, 7);
	InsertSort(list, 7);
	foreachArray(list, 7);
}

// ����ϣ������
void testShellSort() {
	int list[] = { 8,3,6,5,10,0,2 };
	foreachArray(list, 7);
	ShellSort(list, 7);
	foreachArray(list, 7);
}


// ����ð������
void testBubbleSort() {
	int list[] = { 8,3,6,5,10,0,2 };
	foreachArray(list, 7);
	 QuickSort(list, 7);
	// maopaoSort(list, 7);
	foreachArray(list, 7);
}

// ���Կ�������
void testQuickSort() {
	int list[] = { 8,3,6,5,10,0,2,4,1,7 };
	foreachArray(list, 10);
	QuickSort(list, 10);
	foreachArray(list, 10);
}

// ���Թ鲢����
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

//   ��ŵ��
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

	// StringReversePrint();
	// testHeapSort();
	// testInsertSort();
	// testShellSort();
	// testBubbleSort();
	// testQuickSort();
	testRadixSort();
	return 0;

}