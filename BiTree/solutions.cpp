#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
#include "stack.h"

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
