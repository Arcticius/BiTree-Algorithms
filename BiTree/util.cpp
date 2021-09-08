#include "bitree.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void CreateBiTree(BiTree* T) {
	ElemType ch;
	scanf_s("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(0);
		(*T)->data = ch;
		CreateBiTree(&((*T)->lchild));
		CreateBiTree(&((*T)->rchild));
	}
}

void PreOrder(BiTree T) {
	if (T != NULL) {
		printf("%c ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		printf("%c ", T->data);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ", T->data);
	}
}

void InitStack(SqStack& S) {
	S.top = -1;
}

bool IsEmpty(SqStack S) {
	return S.top == -1;
}

bool Push(SqStack& S, BiTree x) {
	if (S.top == MAXSIZE - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack& S, BiTree& x) {
	if (IsEmpty(S))
		return false;
	x = S.data[S.top--];
	return true;
}

bool GetTop(SqStack S, BiTree& x) {
	if (IsEmpty(S))
		return false;
	x = S.data[S.top];
	return true;
}

void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}

bool IsEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

bool EnQueue(SqQueue& Q, BiTree x) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}

bool DeQueue(SqQueue& Q, BiTree& x) {
	if (IsEmpty(Q))
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

