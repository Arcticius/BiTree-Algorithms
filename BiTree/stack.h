#pragma once
#include <stdio.h>
#define MAXSIZE 50
#include"bitree.h"

typedef struct {
	BiTree data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack& S);
bool IsEmpty(SqStack S);
bool Push(SqStack& S, BiTree x);
bool Pop(SqStack& S, BiTree& x);
bool GetTop(SqStack S, BiTree& x);