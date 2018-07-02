#pragma once
#include <stdio.h>
// 堆栈  顺序结构 
/*
	主要用一维数组存储
*/

typedef int Position;
typedef struct SNode * PtrToSNode;
struct SNode {
	int * Data;   // 存储元素的数组
	Position Top; // 栈顶指针
	int MaxSize;  // 最大容量
};
typedef PtrToSNode Stack;

// 创建堆栈
Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (int *)malloc(MaxSize * sizeof(int));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull(Stack S) {
	return (S->Top == S->MaxSize - 1);
}

bool Push(Stack S, int X)
{
	if (IsFull(S)) {
		printf("堆栈已满！");
		return false;
	}
	else
	{
		S->Data[++(S->Top)] = X;
		return true;
	}
}

bool IsEmpty(Stack S)
{
	return (S->Top == -1);
}

int  Pop(Stack S)
{
	if (IsEmpty(S)) {
		printf("堆栈已经空了！\n");
		return -1;
	}
	printf("取出数据:%d\n", S->Data[S->Top]);
	// 下面会先执行S->Data[S->Top],再执行--；
	return (S->Data[(S->Top)--]);
}

void test() {
	Stack s = CreateStack(3);
	Push(s, 11);
	Push(s, 22);
	Push(s, 33);
	printf("取出堆栈数据：%d\n", Pop(s));
	printf("取出堆栈数据：%d\n", Pop(s));
	printf("取出堆栈数据：%d\n", Pop(s));
	printf("取出堆栈数据：%d\n", Pop(s));
}