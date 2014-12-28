#ifndef _QUEUE_H
#define _QUEUE_H

typedef char queueElementT;

typedef struct queueTag {
    queueElementT element;
    struct queueTag *next;
} queueNodeT;

typedef struct {
    queueNodeT *firstNode;
    queueNodeT *lastNode;
} queueT;

void QueueInit(queueT *queueP);

void QueueDestroy(queueT *queueP);

void Enqueue(queueT *queueP, queueElementT element);
queueElementT Dequeue(queueT *queueP);

int QueueIsEmpty(queueT *queueP);

#endif
