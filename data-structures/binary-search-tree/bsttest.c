#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void)
{
    treeT tree;
    int input = 0;

    TreeInit(&tree);

    do {
        printf("Enter a number: ");
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        TreeInsert(&tree, input);
    } while (input != 0);

    printf("Size of tree is %d\n", TreeSize(&tree));
    printf("Depth of tree is %d\n", TreeMaxDepth(&tree));
    printf("Minimum value in tree is %d\n", TreeMinValue(&tree));

    TreePrint(&tree);
    printf("\n");
    TreePrintPostOrder(&tree);

    TreeDestroy(&tree);

    return 0;
}
