#pragma once
#include <stdio.h>
#include "malloc.h"

// 队列 顺序结构
typedef int Position;
typedef struct QNode *  PtrToQNode;
struct QNode {
	int *Data;		// 存储元素的数组
	Position Front, Rear;  // 队列的头、尾指针
	int MaxSize; // 最大容量
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
		printf("队列满了！");
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
		printf("当前队列为空");
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
	printf("删除%d\n", DeleteQ(q));
	printf("删除%d\n", DeleteQ(q));
	printf("删除%d\n", DeleteQ(q));
}