#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void QueueInit(queueT *queueP)
{
    queueP->firstNode = NULL;
    queueP->lastNode = NULL;
}

void QueueDestroy(queueT *queueP)
{
    while (!QueueIsEmpty(queueP)) {
        Dequeue(queueP);
    }
}

void Enqueue(queueT *queueP, queueElementT element)
{
    queueNodeT *node = (queueNodeT *) malloc(sizeof(queueNodeT));

    node->element = element;

    if (QueueIsEmpty(queueP)) {
        node->next = NULL;
        queueP->firstNode = node;
        queueP->lastNode = node;
    } else {
        queueP->lastNode->next = node;
        queueP->lastNode = node;
    }
}

queueElementT Dequeue(queueT *queueP)
{
    queueNodeT *node = queueP->firstNode;
    queueElementT element = node->element;

    queueP->firstNode = node->next;
    free(node);

    return element;
}

int QueueIsEmpty(queueT *queueP)
{
    return queueP->firstNode == NULL;
}
