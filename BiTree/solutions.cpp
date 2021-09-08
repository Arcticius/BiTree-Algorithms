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

void PostOrderNR(BiTree T) { //非递归后续遍历
	SqStack S; InitStack(S);
	BiTree p, r; //r用于标记已访问的结点，区分弹出栈顶返回结点是左子树or右子树

	p = T; r = NULL;
	while (p || !IsEmpty(S)) {
		if (p) {
			Push(S, p); //一路向左
			p = p->lchild;
		}
		else { // 左子树为空时
			GetTop(S, p); //读取栈顶结点
			if (p->rchild && p->rchild != r) //若右子树存在且未被访问
				p = p->rchild; //转向右子树
			else { //否则，弹出结点并访问，直到上述条件满足为止
				Pop(S, p);
				printf("%c ", p->data);
				r = p; //记录最近访问过的结点
				p = NULL; //继续执行else分支
			}
		}
	}
}

void InvertLevelOrder(BiTree T) { //逆序层次遍历
	SqStack S; SqQueue Q;
	BiTree p;
	if (T != NULL) {
		InitStack(S); InitQueue(Q);
		EnQueue(Q, T); //根节点入队
		while (!IsEmpty(Q)) {
			DeQueue(Q, p); //出队入栈
			Push(S, p);
			if (p->lchild != NULL)
				EnQueue(Q, p->lchild);
			if (p->rchild != NULL)
				EnQueue(Q, p->rchild);
		}

		while (!IsEmpty(S)) { //逐一出栈
			Pop(S, p);
			printf("%c ", p->data);
		}
	}
}

int BtDepth(BiTree T) {  //非递归求二叉树高度
	if (!T) //树为空，高度为0
		return 0;

	SqQueue Q; InitQueue(Q); //采用层序遍历
	int last = 1, level = 0; //last指向当前层的最右结点

	EnQueue(Q, T); //根结点入队
	BiTree p;
	while (!IsEmpty(Q)) {
		DeQueue(Q, p); //出队
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
		if (Q.front == last) { //处理该层的最右结点
			level++;
			last = Q.rear;
		}
	}

	return level;
}

BiTree PreInCreate(ElemType prelist[], ElemType inlist[], int l1, int h1, int l2, int h2) { //根据先序、中序序列建立二叉树
	//l1,h1表示先序的第一和最后一个结点下标，l2,h2表示中序的第一和最后一个结点下标
	BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode)); //根结点
	int llen, rlen; //左右子树序列长度
	int i;
	
	root->data = prelist[l1]; //l1一定指向根结点位置

	for (i = l2; inlist[i] != root->data; i++); //查找根结点在中序序列中的位置
	llen = i - l2; //划分左右子树
	rlen = h2 - i;

	if (llen) //左子树不空，递归建立左子树
		root->lchild = PreInCreate(prelist, inlist, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;

	if (rlen) //右子树不空，递归建立右子树
		root->rchild = PreInCreate(prelist, inlist, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;

	return root;
}

bool IsComplete(BiTree T) { //是否是完全二叉树
	SqQueue Q; InitQueue(Q);
	BiTree p;

	if (!T) //空树为满二叉树
		return true;

	EnQueue(Q, T);
	while (!IsEmpty(Q)) {
		DeQueue(Q, p);
		if (p != NULL) { //结点不空，左右子树入队（包括空结点）
			EnQueue(Q, p->lchild);
			EnQueue(Q, p->rchild);
		}
		else { //结点为空，查看其后是否有非空结点
			while (!IsEmpty(Q)) {
				DeQueue(Q, p);
				if (p != NULL)
					return false;
			}
		}
	}

	return true;
}