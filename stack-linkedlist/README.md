# 연결 리스트 기반 스택 (Stack using Linked List)

## 개념

**스택(Stack)은** 나중에 들어온 데이터가 먼저 나가는 **FILO (First-In, Last-Out)** 구조의 선형 자료구조이다. **연결 리스트(Linked List) 기반의** 스택은 **크기의 제한이 없다는 장점이** 있으나, **불필요한 메모리 공간을 많이 소모한다는 단점이** 있다.

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

**6. 메모리 해제 (freeStack)**

스택에 사용된 메모리 해제

## 테스트 

```c
#include <stdio.h>
#include "stack-linkedlist.h"

int main() {
    Stack *stack = createStack();
    int value;

    if (!pop(stack, &value))
        printf("pop 실패 (empty)\n");

    if (!peek(stack, &value))
        printf("peek 실패 (empty)\n");

    for (int i = 1; i <= 5; i++) {
        if (push(stack, i * 10))
            printf("push %d\n", i * 10);
        else
            printf("push 실패\n");
    }

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

## 기타

### push 함수의 리턴 형식

**관점 A.**

malloc의 실패는 프로그램 자체의 실패를 의미, 즉 push는 void여야 함.

**관점 B.**

코드의 일관성 측면에서 push또한 bool을 반환할 필요 있음, malloc 실패를 프로그램의 실패로 간주하는 것은 과도한 제한조건임.

> 이 구현에서는 라이브러리 사용자의 자유도를 고려하여 bool을 반환하도록 설계하였음