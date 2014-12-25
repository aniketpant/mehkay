#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void StackInit(stackT *stackP)
{
    stackNodeT *node = (stackNodeT *) malloc(sizeof(stackNodeT));

    node->next = NULL;
    stackP->top = node;
}

void StackDestroy(stackT *stackP)
{
    while (!StackIsEmpty(stackP)) {
        StackPop(stackP);
    }
}

void StackPush(stackT *stackP, stackElementT element)
{
    stackNodeT *node = (stackNodeT *) malloc(sizeof(stackNodeT));

    node->element = element;
    node->next = stackP->top;
    stackP->top = node;
}

stackElementT StackPop(stackT *stackP)
{
    stackNodeT *node = stackP->top;
    stackElementT element = node->element;

    stackP->top = node->next;
    free(node);

    return element;
}

int StackIsEmpty(stackT *stackP)
{
    return stackP->top->next == NULL;
}
