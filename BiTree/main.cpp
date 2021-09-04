#include <stdio.h>
#include "bitree.h"
#include "stack.h"
#include "queue.h"

int main()
{
    BiTree T = NULL;

    CreateBiTree(&T);
    PreOrder(T); printf("\n");
    InOrder(T); printf("\n");
    PostOrder(T); printf("\n");

    return 0;
}
