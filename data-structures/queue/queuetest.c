#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(void)
{
    queueT queue;
    char str[101];
    char *traverse;

    printf("Enter a string: ");

    gets(str);

    QueueInit(&queue);

    for (traverse = str; *traverse != '\0'; traverse++) {
        Enqueue(&queue, *traverse);
    }

    printf("\nDequeued characters are: ");

    while (!QueueIsEmpty(&queue)) {
        printf("%c", Dequeue(&queue));
    }

    printf("\n");

    QueueDestroy(&queue);

    return 0;
}
