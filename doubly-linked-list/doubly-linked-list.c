#include <stdio.h>
#include <stdlib.h>
#include "doubly-linked-list.h"

DoublyLinkedList* createList() {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    if (!list) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertFront(DoublyLinkedList* list, int data) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->prev = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
    }
    else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void insertBack(DoublyLinkedList* list, int data) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->prev = NULL;
    }
    else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void deleteFront(DoublyLinkedList* list) {
    if (list->head == NULL)
        return;

    Node *temp = list->head;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->head = temp->next;
        list->head->prev = NULL;
    }

    free(temp);
}

void deleteBack(DoublyLinkedList* list) {
    if (list->tail == NULL)
        return;

    Node *temp = list->tail;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail = temp->prev;
        list->tail->next = NULL;
    }

    free(temp);
}

Node* search(DoublyLinkedList* list, int target) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data == target)
            return current;
        current = current->next;
    }
    return NULL;
}

void printForward(const DoublyLinkedList* list) {
    Node *current = list->head;

    if (current == NULL) {
        printf("[ HEAD | NULL ] <=> [ NULL | TAIL ]\n");
        return;
    }

    printf("[ HEAD | * ] => ");

    while (current != NULL) {
        if (current->next != NULL)
            printf("[ * | %2d | * ] <=> ", current->data);
        else
            printf("[ * | %2d | * ] <= [ * | TAIL ]", current->data);
        current = current->next;
    }

    printf("\n");
}

void printBackward(const DoublyLinkedList* list) {
    Node *current = list->tail;

    if (current == NULL) {
        printf("[ TAIL | NULL ] <=> [ NULL | HEAD ]\n");
        return;
    }

    printf("[ TAIL | * ] => ");

    while (current != NULL) {
        if (current->prev != NULL)
            printf("[ * | %2d | * ] <=> ", current->data);
        else
            printf("[ * | %2d | * ] <= [ * | HEAD ]", current->data);
        current = current->prev;
    }

    printf("\n");
}

void freeList(DoublyLinkedList* list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}