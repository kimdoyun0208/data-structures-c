# 연결 리스트 (Linked List)

## 개념

**연결 리스트(Linked List)는** 각 노드(Node)가 데이터를 저장하고, 다음 노드를 가리키는 포인터를 가지는 선형 자료구조이다. 첫 번째 노드를 head라고 하며, 각 노드는 다음 노드의 포인터를 가지고 연결되어 있다. 마지막 노드는 NULL을 가리켜 리스트의 끝을 나타낸다.

이 구조는 배열과 달리 크기를 미리 정할 필요가 없으며, **중간 삽입/삭제에 유리하다.** 하지만 인덱스를 통한 임의 접근은 불가능하고, 원하는 요소를 찾기 위해 처음부터 **순차 탐색을 해야 한다는 단점**이 있다.

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

**7. 출력 (printList)**

리스트의 구조와 데이터를 순차적으로 출력

**8. 메모리 해제 (freeList)**

리스트에 할당된 모든 노드를 해제하고 리스트 자체도 메모리 해제

## 테스트 

```c
#include <stdio.h>
#include "linked-list.h"

int main() {
    LinkedList* list = createList();

    printList(list);

    insertFront(list, 10);
    insertBack(list, 20);
    insertFront(list, 5);
    insertBack(list, 30);

    printf("List after insertions:\n");
    printList(list);

    deleteFront(list);
    printf("After deleting front:\n");
    printList(list);

    deleteBack(list);
    printf("After deleting back:\n");
    printList(list);

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