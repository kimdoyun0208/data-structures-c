# 이중 연결 리스트 (Doubly Linked List)

## 개념

**이중 연결 리스트(Doubly Linked List)는** 각 노드가 데이터를 저장하고, **앞 노드(prev)와 뒤 노드(next)를** 동시에 가리키는 양방향 선형 자료구조이다. 리스트는 head와 tail 포인터를 통해 양쪽 끝을 추적한다.

이 구조는 **역방향으로 접근이 가능해** 단일 연결 리스트(Linked List) 보다 효율적인 삽입, 삭제가 가능하다. 하지만 포인터를 2개 사용하기 때문에 **메모리의 사용량이 상대적으로 증가**하고, 구현이 조금 더 복잡하다는 단점이 있다.

## 구현된 기능

**1. 리스트 생성 (createList)**

동적으로 메모리를 할당해 빈 리스트 생성

**2. 앞 삽입 (insertFront)**

리스트 맨 앞에 노드를 삽입

**3. 뒤 삽입 (insertBack)**

리스트 맨 뒤에 노드를 삽입

**4. 앞 삭제 (deleteFront)**

리스트 맨 앞의 노드를 삭제

**5. 뒤 삭제 (deleteBack)**

리스트 맨 뒤의 노드를 삭제

**6. 탐색 (search)**

특정 값을 가지는 노드를 순차적으로 탐색하여 반환

**7. 출력 (printForward)**

리스트의 구조와 데이터를 앞에서부터 순차적으로 출력

**8. 출력 (printBackword)**

리스트의 구조와 데이터를 뒤에서부터 순차적으로 출력

**9. 메모리 해제 (freeList)**

리스트에 할당된 모든 노드를 해제하고 리스트 자체도 메모리 해제

## 테스트 

```c
#include <stdio.h>
#include "doubly-linked-list.h"

int main() {
    DoublyLinkedList* list = createList();

    printForward(list);
    printBackward(list);

    insertFront(list, 10);
    insertBack(list, 20);
    insertFront(list, 5);
    insertBack(list, 30);

    printf("List after insertions:\n");
    printForward(list);
    printBackward(list);

    deleteFront(list);
    printf("After deleting front:\n");
    printForward(list);
    printBackward(list);

    deleteBack(list);
    printf("After deleting back:\n");
    printForward(list);
    printBackward(list);

    int target = 20;
    Node* result = search(list, target);
    if (result) {
        printf("Value %d found in list.\n", target);
    } else {
        printf("Value %d not found in list.\n", target);
    }

    freeList(list);
    return 0;
}
```