#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>

typedef struct Queue {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity);
bool enqueue(Queue* queue, int value);
bool dequeue(Queue* queue, int* out);
bool isEmpty(const Queue* queue);
bool isFull(const Queue* queue);
int getSize(const Queue* queue);
void freeQueue(Queue* queue);

#endif // QUEUE_ARRAY_H