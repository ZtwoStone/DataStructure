#pragma once

#include <stdio.h>
#include "malloc.h"
// 堆栈


//堆栈  链式结构
/*
头指针只有next，没有data
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
		printf("当前堆栈为空！");
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
	printf("出站数据为:%d\n", Pop(s));
	printf("出站数据为:%d\n", Pop(s));
	printf("出站数据为:%d\n", Pop(s));
}
