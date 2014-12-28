#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(void)
{
    stackT stack;
    char str[101];
    char *traverse;

    printf("Enter a string: ");

    gets(str);

    StackInit(&stack, strlen(str));

    for (traverse = str; *traverse != '\0'; traverse++) {
        StackPush(&stack, *traverse);
    }

    printf("\nPopped characters are: ");

    while (!StackIsEmpty(&stack)) {
        printf("%c", StackPop(&stack));
    }

    printf("\n");

    StackDestroy(&stack);

    return 0;
}
