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