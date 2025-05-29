# 배열 기반 큐 (Queue using Array)

## 개념

**큐(Queue)는** 먼저 들어온 데이터가 먼저 나가는 **FIFO (First-In, First-Out)** 구조의 선형 자료구조이다. 배열 기반 큐는 고정된 크기의 배열을 사용하며, **순환 구조 (Circular Queue)로** 구현하여 공간을 효율적으로 사용한다.

## 구현된 기능

**1. 큐 생성 (createQueue)**

주어진 크기의 빈 큐 생성

**2. 삽입 (enqueue)**

큐의 rear에 데이터를 삽입

**3. 삭제 (dequeue)**

큐의 front에서 데이터를 꺼냄

**4. 빈 큐 확인 (isEmpty)**

큐가 비어있는지 확인

**5. 가득찬 큐 확인 (isFull)**

큐가 가득 찼는지 확인

**6. 크기 조회 (getSize)**

현재 큐에 저장된 원소 개수 반환

**7. 메모리 해제 (freeQueue)**

큐에 사용된 메모리를 모두 해제

## 테스트 

```c
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
```