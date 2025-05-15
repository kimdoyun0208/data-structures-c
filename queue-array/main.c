#include <stdio.h>
#include "queue-array.h"

int main() {
    Queue *queue = createQueue(5);
    int value;

    if (!dequeue(queue, &value))
        printf("dequeue 실패 (empty)\n");

    if (getSize(queue) == 0)
        printf("큐 크기: 0\n");

    for (int i = 1; i <= 5; i++) {
        if (enqueue(queue, i * 10))
            printf("enqueue %d\n", i * 10);
        else
            printf("enqueue 실패 (full)\n");
    }

    if (!enqueue(queue, 999)) printf("enqueue 실패 (full)\n");

    for (int i = 0; i < 3; i++) {
        if (dequeue(queue, &value))
            printf("dequeue: %d\n", value);
    }

    for (int i = 100; i <= 200; i += 50) {
        if (enqueue(queue, i))
            printf("enqueue %d\n", i);
    }

    while (dequeue(queue, &value)) {
        printf("dequeue: %d\n", value);
    }

    if (!dequeue(queue, &value))
        printf("dequeue 실패 (empty)\n");
        
    printf("최종 큐 크기: %d\n", getSize(queue));

    freeQueue(queue);
    return 0;
}