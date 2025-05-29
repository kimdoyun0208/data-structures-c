# 배열 기반 스택 (Stack using Array)

## 개념

**스택(Stack)은** 나중에 들어온 데이터가 먼저 나가는 **FILO (First-In, Last-Out)** 구조의 선형 자료구조이다. 배열을 기반으로 스택을 구현하면, top 인덱스를 이용해 삽입(push)과 삭제(pop)가 O(1) 시간 복잡도로 수행되어 **좋은 성능을** 가지지만 **크기에 제한이 있다는 단점이** 있다.

## 구현된 기능

**1. 스택 생성 (createStack)**

주어진 크기의 빈 스택 생성

**2. 삽입 (push)**

스택의 top에 데이터를 삽입

**3. 삭제 (pop)**

스택의 top에서 데이터를 꺼냄

**4. top 확인 (peek)**

스택의 top 값을 확인

**5. 빈 스택 확인 (isEmpty)**

스택이 비어있는지 확인

**6. 가득찬 스택 확인 (isFull)**

스택이 가득 찼는지 확인

**7. 메모리 해제 (freeStack)**

스택에 사용된 메모리 해제

## 테스트 

```c
#include <stdio.h>
#include "stack-array.h"

int main() {
    Stack *stack = createStack(5);
    
    int value;

    if (!pop(stack, &value))
        printf("pop 실패 (empty)\n");

    if (!peek(stack, &value))
        printf("peek 실패 (empty)\n");

    for (int i = 1; i <= 5; i++) {
        if (push(stack, i * 10))
            printf("push %d\n", i * 10);
        else
            printf("push 실패 (full)\n");
    }

    if (!push(stack, 999))
        printf("push 실패 (full)\n");

    if (peek(stack, &value))
        printf("peek: %d\n", value);

    while (pop(stack, &value)) {
        printf("pop: %d\n", value);
    }

    if (!pop(stack, &value))
        printf("pop 실패 (empty)\n");

    if (!peek(stack, &value))
        printf("peek 실패 (empty)\n");

    freeStack(stack);
    return 0;
}
```