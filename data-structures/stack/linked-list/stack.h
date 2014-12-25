#ifndef _STACK_H
#define _STACK_H

typedef char stackElementT;

typedef struct stackTag {
    stackElementT element;
    struct stackTag *next;
} stackNodeT;

typedef struct {
    stackNodeT *top;
} stackT;

void StackInit(stackT *stackP);

void StackDestroy(stackT *stackP);

void StackPush(stackT *stackP, stackElementT element);
stackElementT StackPop(stackT *stackP);

int StackIsEmpty(stackT *stackP);

#endif
