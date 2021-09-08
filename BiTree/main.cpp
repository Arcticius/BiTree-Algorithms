#include <stdio.h>
#include "bitree.h"
#include "stack.h"
#include "queue.h"

int main()
{
    BiTree T = NULL;

    /*char prelist[] = "ABCDEFGHI";
    char inlist[] = "BCAEDGHFI";
    T = PreInCreate(prelist, inlist, 0, 8, 0, 8);
    PreOrder(T);
    printf("\n");
    InOrder(T);*/

    CreateBiTree(&T);
    IsComplete(T) ? printf("This tree is complete.\n") : printf("This tree is NOT complete.\n");

    return 0;
}
