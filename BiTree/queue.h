#pragma once
#define MAXSIZE 50
#include "bitree.h"

typedef struct {
	ElemType data[MAXSIZE];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue& Q);
bool IsEmpty(SqQueue Q);
bool EnQueue(SqQueue& Q, ElemType x);
bool DeQueue(SqQueue& Q, ElemType& x);
#pragma once
