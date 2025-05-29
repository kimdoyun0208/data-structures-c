#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue-linkedlist.h"

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));

    if (!queue) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

// 관점 A.
// malloc의 실패는 프로그램 자체의 실패를 의미, 즉 enqueue는 void여야 함.
// 관점 B.
// 코드의 일관성 측면에서 enqueue또한 bool을 반환할 필요 있음, malloc 실패를 프로그램의 실패로 간주하는 것은 과도한 제한조건임.
bool enqueue(Queue* queue, int value) {
    Node* newNode = malloc(sizeof(Node));

    if(!newNode) {
        printf("Memory allocation failed\n");
        return false; // Note: 여기서만 리턴 해주면 코드의 일관성에 문제가 있을 수 있어 보임
    }

    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
    return true;
}

bool dequeue(Queue* queue, int* out) {
    if(isEmpty(queue))
        return false;

    Node* temp = queue->front;
    *out = temp->data;
    queue->front = temp->next;

    if(queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    queue->size--;
    return true;
}

bool isEmpty(const Queue* queue) {
    return queue->size == 0;
}

int getSize(const Queue* queue) {
    return queue->size;
}

void freeQueue(Queue* queue) {
    Node* current = queue->front;
    
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
    queue = NULL;
}