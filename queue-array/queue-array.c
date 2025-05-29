#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue-array.h"

Queue* createQueue(int capacity) {
    Queue* queue = malloc(sizeof(Queue));

    if (!queue) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    queue->data = malloc(sizeof(int) * capacity);

    if (!queue->data) {
        printf("Memory allocation failed for queue data.\n");
        free(queue);
        exit(EXIT_FAILURE);
    }

    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;

    return queue;
}

bool enqueue(Queue* queue, int value) {
    if(isFull(queue))
        return false;
    
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
    return true;
}

bool dequeue(Queue* queue, int* out) {
    if(isEmpty(queue))
        return false;

    *out = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return true;
}

bool isEmpty(const Queue* queue) {
    return queue->size == 0;
}

bool isFull(const Queue* queue) {
    return queue->size == queue->capacity;
}

int getSize(const Queue* queue) {
    return queue->size;
}

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
    queue = NULL;
}