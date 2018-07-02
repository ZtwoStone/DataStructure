#pragma once
#include <stdio.h>
#include "malloc.h"

// ���� ˳��ṹ
typedef int Position;
typedef struct QNode *  PtrToQNode;
struct QNode {
	int *Data;		// �洢Ԫ�ص�����
	Position Front, Rear;  // ���е�ͷ��βָ��
	int MaxSize; // �������
};
typedef PtrToQNode Quene;

Quene CreateQuene(int MaxSize)
{
	Quene q = (Quene)malloc(sizeof(struct QNode));
	q->Data = (int *)malloc(MaxSize * sizeof(int));
	q->Front = q->Rear = 0;
	q->MaxSize = MaxSize;
	return q;
}

bool IsFull(Quene q)
{
	return ((q->Rear + 1) % q->MaxSize == q->Front);
}

bool AddQ(Quene q, int x) {
	if (IsFull(q)) {
		printf("�������ˣ�");
		return false;
	}
	else
	{
		q->Rear = (q->Rear + 1) % (q->MaxSize);
		q->Data[q->Rear] = x;
		return true;
	}
}

bool IsEmpty(Quene q)
{
	return q->Front == q->Rear;
}

int DeleteQ(Quene q)
{
	if (IsEmpty(q)) {
		printf("��ǰ����Ϊ��");
		return -1;
	}
	else {
		q->Front = (q->Front + 1) % (q->MaxSize);
		return q->Data[q->Front];
	}
}

void test() {
	Quene q = CreateQuene(3);
	AddQ(q, 111);
	AddQ(q, 222);
	AddQ(q, 333);

	// foreachArray(q->Data, 3);
	printf("ɾ��%d\n", DeleteQ(q));
	printf("ɾ��%d\n", DeleteQ(q));
	printf("ɾ��%d\n", DeleteQ(q));
}