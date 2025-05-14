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