#pragma once
#include <stdio.h>
#define MAXSIZE 50
#include"bitree.h"

typedef struct {
	ElemType data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack& S);
bool IsEmpty(SqStack S);
bool Push(SqStack& S, ElemType x);
bool Pop(SqStack& S, ElemType& x);
bool GetTop(SqStack S, ElemType& x);