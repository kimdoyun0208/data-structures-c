#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack-array.h"

Stack* createStack(int capacity) {
    Stack* stack = malloc(sizeof(Stack));

    if (!stack) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    stack->data = malloc(sizeof(int) * capacity);

    if (!stack->data) {
        printf("Memory allocation failed\n");
        free(stack);
        exit(EXIT_FAILURE);
    }

    stack->capacity = capacity;
    stack->top = -1;

    return stack;
}

bool push(Stack* stack, int value) {
    if (isFull(stack))
        return false;
    
    stack->top++;
    stack->data[stack->top] = value;

    return true;
}

bool pop(Stack* stack, int* out) {
    if (isEmpty(stack))
        return false;

    *out = stack->data[stack->top];
    stack->top--;

    return true;
}

bool peek(const Stack* stack, int* out) {
    if (isEmpty(stack))
        return false;
    
    *out = stack->data[stack->top];
    return true;
}

bool isEmpty(const Stack* stack) {
    return stack->top == -1;
}

bool isFull(const Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}