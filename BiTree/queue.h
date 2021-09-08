#pragma once
#define MAXSIZE 50
#include "bitree.h"

typedef struct {
	BiTree data[MAXSIZE];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue& Q);
bool IsEmpty(SqQueue Q);
bool EnQueue(SqQueue& Q, BiTree x);
bool DeQueue(SqQueue& Q, BiTree& x);
#pragma once
