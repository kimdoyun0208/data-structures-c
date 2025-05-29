#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack-linkedlist.h"

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));

    if (!stack) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    stack->top = NULL;
    return stack;
}

bool push(Stack* stack, int value) {
    Node* newNode = malloc(sizeof(Node));

    if (!newNode) {
        printf("Memory allocation failed\n");
        return false; // Note: 여기서만 리턴 해주면 코드의 일관성에 문제가 있을 수 있어 보임
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    return true;
}

bool pop(Stack* stack, int* out) {
    if(isEmpty(stack))
        return false;
    
    Node* temp = stack->top;
    *out = temp->data;
    stack->top = temp->next;
    free(temp);
    return true;
}

bool peek(const Stack* stack, int* out) {
    if(isEmpty(stack))
        return false;

    *out = stack->top->data;
    return true;
}

bool isEmpty(const Stack* stack) {
    return stack->top == NULL;
}

void freeStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
    stack = NULL;
}