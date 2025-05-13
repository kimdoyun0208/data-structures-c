#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* createList();
void insertFront(LinkedList* list, int data);
void insertBack(LinkedList* list, int data);
void deleteFront(LinkedList* list);
void deleteBack(LinkedList* list);
Node* search(LinkedList* list, int target);
void printList(const LinkedList* list);
void freeList(LinkedList* list);

#endif // LINKED_LIST_H