#pragma once
#include <stdio.h>
// ��ջ  ˳��ṹ 
/*
	��Ҫ��һά����洢
*/

typedef int Position;
typedef struct SNode * PtrToSNode;
struct SNode {
	int * Data;   // �洢Ԫ�ص�����
	Position Top; // ջ��ָ��
	int MaxSize;  // �������
};
typedef PtrToSNode Stack;

// ������ջ
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
		printf("��ջ������");
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
		printf("��ջ�Ѿ����ˣ�\n");
		return -1;
	}
	printf("ȡ������:%d\n", S->Data[S->Top]);
	// �������ִ��S->Data[S->Top],��ִ��--��
	return (S->Data[(S->Top)--]);
}

void test() {
	Stack s = CreateStack(3);
	Push(s, 11);
	Push(s, 22);
	Push(s, 33);
	printf("ȡ����ջ���ݣ�%d\n", Pop(s));
	printf("ȡ����ջ���ݣ�%d\n", Pop(s));
	printf("ȡ����ջ���ݣ�%d\n", Pop(s));
	printf("ȡ����ջ���ݣ�%d\n", Pop(s));
}