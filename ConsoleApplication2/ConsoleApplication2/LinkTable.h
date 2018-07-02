#pragma once

#include "stdafx.h"
#include "malloc.h"

/*
	单链表方法
*/


typedef struct Node *PtrToNode;

struct Node
{
	int data;
	PtrToNode Next;
};

// 创建新的单链表
PtrToNode create(int size) {
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	p->Next = NULL;
	while (size > 0) {
		PtrToNode t = (PtrToNode)malloc(sizeof(struct Node));
		t->data = size * 11;
		t->Next = p->Next;
		p->Next = t;
		size--;
	}
	return p;
}

// 遍历输出数据
void forEach(PtrToNode p) {
	while (p != NULL)
	{
		printf("%d  ,  ", p->data);
		p = p->Next;
	}
	printf("\n");
}

// 删除指定位置的数据
int deleteItem(PtrToNode p, int position) {

	while (position > 1) {
		p = p->Next;
		position--;
	}
	PtrToNode pre = p;
	PtrToNode d = p->Next;
	pre->Next = d->Next;
	d->Next = NULL;
	printf("---------%d------\n", d->data);
	free(d);
	return 0;
}

// 反转
PtrToNode Reverse(PtrToNode L) {
	PtrToNode old_head, new_head, temp;
	old_head = L;
	new_head = NULL;
	while (old_head) {
		temp = old_head->Next;
		old_head->Next = new_head;
		new_head = old_head;
		old_head = temp;
	}
	L = new_head;
	return L;
}

int LinkTablemain()
{
	printf("Hello World!\n");

	PtrToNode p = create(10);
	forEach(p);

	deleteItem(p, 5);
	forEach(p);


	forEach(Reverse(p));

	free(p);
	return 0;

}