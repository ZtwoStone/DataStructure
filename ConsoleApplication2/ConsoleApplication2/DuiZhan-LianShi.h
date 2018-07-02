#pragma once

#include <stdio.h>
#include "malloc.h"
// ��ջ


//��ջ  ��ʽ�ṹ
/*
ͷָ��ֻ��next��û��data
*/
typedef struct SNode * PtrToSNode;
struct SNode {
	int Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack createStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty(Stack s) {
	return (s->Next == NULL);
}

bool Push(Stack s, int data)
{
	Stack temp;
	temp = (Stack)malloc(sizeof(struct SNode));
	temp->Next = s->Next;
	temp->Data = data;
	s->Next = temp;
	return true;
}

int Pop(Stack s)
{
	if (IsEmpty(s)) {
		printf("��ǰ��ջΪ�գ�");
		return -1;
	}
	else
	{
		int data;
		Stack temp;
		temp = s->Next;
		s->Next = temp->Next;
		data = temp->Data;
		free(temp);
		return data;
	}
}


void test() {
	Stack s = createStack();
	Push(s, 11);
	Push(s, 22);
	Push(s, 33);
	printf("��վ����Ϊ:%d\n", Pop(s));
	printf("��վ����Ϊ:%d\n", Pop(s));
	printf("��վ����Ϊ:%d\n", Pop(s));
}
