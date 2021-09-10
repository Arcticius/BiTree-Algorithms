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

void PostOrderNR(BiTree T); //�ǵݹ��������
void InvertLevelOrder(BiTree T); //�����α���
int BtDepth(BiTree T); //�ǵݹ���������߶�
BiTree PreInCreate(ElemType prelist[], ElemType inlist[], int l1, int h1, int l2, int h2); //���������������н���������
bool IsComplete(BiTree T); //�Ƿ�����ȫ������
int DoubleNodesCount(BiTree T); //˫��֧�����ͳ�ƣ��ݹ鷨
int DoubleNodesCount2(BiTree T); //˫��֧�����ͳ�ƣ�ȫ�ֱ�����
void SwapSubTree(BiTree& T); //������������
ElemType PreOrderK(BiTree T, int k); //���������k�Ľ���ֵ