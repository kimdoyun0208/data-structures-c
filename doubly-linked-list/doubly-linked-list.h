#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

DoublyLinkedList* createList();
void insertFront(DoublyLinkedList* list, int data);
void insertBack(DoublyLinkedList* list, int data);
void deleteFront(DoublyLinkedList* list);
void deleteBack(DoublyLinkedList* list);
Node* search(DoublyLinkedList* list, int target);
void printForward(const DoublyLinkedList* list);
void printBackward(const DoublyLinkedList* list);
void freeList(DoublyLinkedList* list);

#endif // DOUBLY_LINKED_LIST_H