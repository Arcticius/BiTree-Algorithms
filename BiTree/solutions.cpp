#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
#include "stack.h"

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
