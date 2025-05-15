#include <stdio.h>
#include "stack-linkedlist.h"

int main() {
    Stack *stack = createStack();
    int value;

    if (!pop(stack, &value))
        printf("pop 실패 (empty)\n");

    if (!peek(stack, &value))
        printf("peek 실패 (empty)\n");

    for (int i = 1; i <= 5; i++) {
        if (push(stack, i * 10))
            printf("push %d\n", i * 10);
        else
            printf("push 실패\n");
    }

    if (peek(stack, &value))
        printf("peek: %d\n", value);

    while (pop(stack, &value)) {
        printf("pop: %d\n", value);
    }

    if (!pop(stack, &value))
        printf("pop 실패 (empty)\n");

    if (!peek(stack, &value))
        printf("peek 실패 (empty)\n");

    freeStack(stack);
    return 0;
}