#pragma once
typedef char ElemType;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void CreateBiTree(BiTree* T);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
void InOrderNR(BiTree T);
void PreOrderNR(BiTree T);

void PostOrderNR(BiTree T); //非递归后续遍历