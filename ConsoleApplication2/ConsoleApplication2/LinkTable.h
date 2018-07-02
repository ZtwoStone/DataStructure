#pragma once

#include "stdafx.h"
#include "malloc.h"

/*
	��������
*/


typedef struct Node *PtrToNode;

struct Node
{
	int data;
	PtrToNode Next;
};

// �����µĵ�����
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

// �����������
void forEach(PtrToNode p) {
	while (p != NULL)
	{
		printf("%d  ,  ", p->data);
		p = p->Next;
	}
	printf("\n");
}

// ɾ��ָ��λ�õ�����
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

// ��ת
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