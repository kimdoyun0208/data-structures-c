#include <stdio.h>
#include "queue-linkedlist.h"

int main() {
    Queue *queue = createQueue();
    int value;

    if (!dequeue(queue, &value))
        printf("dequeue 실패 (empty)\n");

    if (getSize(queue) == 0)
        printf("큐 크기: 0\n");

    for (int i = 1; i <= 5; i++) {
        enqueue(queue, i * 10);
        printf("enqueue %d\n", i * 10);
    }
    
    enqueue(queue, 999);
    printf("enqueue 999\n");

    printf("큐 크기: %d\n", getSize(queue));

    for (int i = 0; i < 3; i++) {
        if (dequeue(queue, &value))
            printf("dequeue: %d\n", value);
    }

    for (int i = 100; i <= 200; i += 50) {
        enqueue(queue, i);
        printf("enqueue %d\n", i);
    }

    while (dequeue(queue, &value)) {
        printf("dequeue: %d\n", value);
    }

    if (!dequeue(queue, &value))
        printf("dequeue 실패 (empty)\n");

    printf("최종 큐 크기: %d\n", getSize(queue));

    // enqueue보다 dequeue가 훨씬 오래걸림. 왜 그럴까?

    printf("100000000개 enqueue 테스트...\n");
    for (int i = 0; i < 100000000; i++) {
        enqueue(queue, i);
    }

    printf("100000000개 dequeue 테스트...\n");
    for (int i = 0; i < 100000000; i++) {
        dequeue(queue, &value);
    }

    freeQueue(queue);
    return 0;
}
