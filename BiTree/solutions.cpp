#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
#include "stack.h"
#include "queue.h"

void InOrderNR(BiTree T) {
	SqStack S; InitStack(S);
	BiTree p = T;

	while (p || !IsEmpty(S)) {
		if (p) {
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			printf("%c ", p->data);
			p = p->rchild;
		}
	}
}

void PreOrderNR(BiTree T) {
	SqStack S; InitStack(S);
	BiTree p = T;

	while (p || !IsEmpty(S)) {
		if (p) {
			printf("%c ", p->data);
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			p = p->rchild;
		}
	}
}

void LevelOrder(BiTree T) {
	SqQueue Q; InitQueue(Q);
	BiTree p;

	EnQueue(Q, T);
	while (!IsEmpty(Q)) {
		DeQueue(Q, p);
		printf("%c ", p->data);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}

void PostOrderNR(BiTree T) { //�ǵݹ��������
	SqStack S; InitStack(S);
	BiTree p, r; //r���ڱ���ѷ��ʵĽ�㣬���ֵ���ջ�����ؽ����������or������

	p = T; r = NULL;
	while (p || !IsEmpty(S)) {
		if (p) {
			Push(S, p); //һ·����
			p = p->lchild;
		}
		else { // ������Ϊ��ʱ
			GetTop(S, p); //��ȡջ�����
			if (p->rchild && p->rchild != r) //��������������δ������
				p = p->rchild; //ת��������
			else { //���򣬵�����㲢���ʣ�ֱ��������������Ϊֹ
				Pop(S, p);
				printf("%c ", p->data);
				r = p; //��¼������ʹ��Ľ��
				p = NULL; //����ִ��else��֧
			}
		}
	}
}

void InvertLevelOrder(BiTree T) { //�����α���
	SqStack S; SqQueue Q;
	BiTree p;
	if (T != NULL) {
		InitStack(S); InitQueue(Q);
		EnQueue(Q, T); //���ڵ����
		while (!IsEmpty(Q)) {
			DeQueue(Q, p); //������ջ
			Push(S, p);
			if (p->lchild != NULL)
				EnQueue(Q, p->lchild);
			if (p->rchild != NULL)
				EnQueue(Q, p->rchild);
		}

		while (!IsEmpty(S)) { //��һ��ջ
			Pop(S, p);
			printf("%c ", p->data);
		}
	}
}

int BtDepth(BiTree T) {  //�ǵݹ���������߶�
	if (!T) //��Ϊ�գ��߶�Ϊ0
		return 0;

	SqQueue Q; InitQueue(Q); //���ò������
	int last = 1, level = 0; //lastָ��ǰ������ҽ��

	EnQueue(Q, T); //��������
	BiTree p;
	while (!IsEmpty(Q)) {
		DeQueue(Q, p); //����
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
		if (Q.front == last) { //����ò�����ҽ��
			level++;
			last = Q.rear;
		}
	}

	return level;
}

BiTree PreInCreate(ElemType prelist[], ElemType inlist[], int l1, int h1, int l2, int h2) { //���������������н���������
	//l1,h1��ʾ����ĵ�һ�����һ������±꣬l2,h2��ʾ����ĵ�һ�����һ������±�
	BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode)); //�����
	int llen, rlen; //�����������г���
	int i;
	
	root->data = prelist[l1]; //l1һ��ָ������λ��

	for (i = l2; inlist[i] != root->data; i++); //���Ҹ���������������е�λ��
	llen = i - l2; //������������
	rlen = h2 - i;

	if (llen) //���������գ��ݹ齨��������
		root->lchild = PreInCreate(prelist, inlist, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;

	if (rlen) //���������գ��ݹ齨��������
		root->rchild = PreInCreate(prelist, inlist, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;

	return root;
}

bool IsComplete(BiTree T) { //�Ƿ�����ȫ������
	SqQueue Q; InitQueue(Q);
	BiTree p;

	if (!T) //����Ϊ��������
		return true;

	EnQueue(Q, T);
	while (!IsEmpty(Q)) {
		DeQueue(Q, p);
		if (p != NULL) { //��㲻�գ�����������ӣ������ս�㣩
			EnQueue(Q, p->lchild);
			EnQueue(Q, p->rchild);
		}
		else { //���Ϊ�գ��鿴����Ƿ��зǿս��
			while (!IsEmpty(Q)) {
				DeQueue(Q, p);
				if (p != NULL)
					return false;
			}
		}
	}

	return true;
}