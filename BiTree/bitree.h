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
void LevelOrder(BiTree T);

void PostOrderNR(BiTree T); //非递归后续遍历
void InvertLevelOrder(BiTree T); //逆序层次遍历
int BtDepth(BiTree T); //非递归求二叉树高度
BiTree PreInCreate(ElemType prelist[], ElemType inlist[], int l1, int h1, int l2, int h2); //根据先序、中序序列建立二叉树
bool IsComplete(BiTree T); //是否是完全二叉树