#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue();
bool enqueue(Queue* queue, int value);
bool dequeue(Queue* queue, int* out);
bool isEmpty(const Queue* queue);
int getSize(const Queue* queue);
void freeQueue(Queue* queue);

#endif // QUEUE_LINKEDLIST_H