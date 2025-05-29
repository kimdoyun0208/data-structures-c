# 연결 리스트 기반 큐 (Queue using Linked List)

## 개념

**큐(Queue)는** 먼저 들어온 데이터가 먼저 나가는 **FIFO (First-In, First-Out)** 구조의 선형 자료구조이다. **연결 리스트(Linked List) 기반의** 큐는 **크기의 제한이 없다는 장점이** 있으나, **불필요한 메모리 공간을 많이 소모한다는 단점이** 있다.

## 구현된 기능

**1. 큐 생성 (createQueue)**

주어진 크기의 빈 큐 생성

**2. 삽입 (enqueue)**

큐의 rear에 데이터를 삽입

**3. 삭제 (dequeue)**

큐의 front에서 데이터를 꺼냄

**4. 빈 큐 확인 (isEmpty)**

큐가 비어있는지 확인

**5. 크기 조회 (getSize)**

현재 큐에 저장된 원소 개수 반환

**6. 메모리 해제 (freeQueue)**

큐에 사용된 메모리를 모두 해제

## 테스트 

```c
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
```

## 기타

### enqueue 함수의 리턴 형식

**관점 A.**

malloc의 실패는 프로그램 자체의 실패를 의미, 즉 enqueue는 void여야 함.

**관점 B.**

코드의 일관성 측면에서 enqueue또한 bool을 반환할 필요 있음, malloc 실패를 프로그램의 실패로 간주하는 것은 과도한 제한조건임.

> 이 구현에서는 라이브러리 사용자의 자유도를 고려하여 bool을 반환하도록 설계하였음

### 매우 큰 크기(100000000개 이상)의 enqueu, dequeue 작업시 dequeue가 훨씬 오래걸림

조사 필요