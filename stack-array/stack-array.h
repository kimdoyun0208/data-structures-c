#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity);
bool push(Stack* stack, int value);
bool pop(Stack* stack, int* out);
bool peek(const Stack* stack, int* out);
bool isEmpty(const Stack* stack);
bool isFull(const Stack* stack);
void freeStack(Stack* stack);

#endif // STACK_ARRAY_H