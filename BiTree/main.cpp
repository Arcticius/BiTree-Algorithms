#include <stdio.h>
#include "bitree.h"
#include "stack.h"
#include "queue.h"

int main()
{
    BiTree T = NULL;

    CreateBiTree(&T);

    PostOrder(T); printf("\n");
    PostOrderNR(T);

    return 0;
}
