#include <stdio.h>
#include "stack-array.h"

int main() {
    Stack *stack = createStack(5);
    
    int value;

    if (!pop(stack, &value))
        printf("pop 실패 (empty)\n");

    if (!peek(stack, &value))
        printf("peek 실패 (empty)\n");

    for (int i = 1; i <= 5; i++) {
        if (push(stack, i * 10))
            printf("push %d\n", i * 10);
        else
            printf("push 실패 (full)\n");
    }

    if (!push(stack, 999))
        printf("push 실패 (full)\n");

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