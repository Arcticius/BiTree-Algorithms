#include <stdio.h>
#include "bitree.h"
#include "stack.h"
#include "queue.h"

int main()
{
    BiTree T = NULL;

    CreateBiTree(&T);
    printf("%c", PreOrderK(T, 5));

    return 0;
}
