#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack();
bool push(Stack* stack, int value);
bool pop(Stack* stack, int* out);
bool peek(const Stack* stack, int* out);
bool isEmpty(const Stack* stack);
void freeStack(Stack* stack);

#endif // STACK_LINKEDLIST_H