#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

LinkedList* createList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    if (!list) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

void insertFront(LinkedList* list, int data) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertBack(LinkedList* list, int data) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteFront(LinkedList* list) {
    if (list->head == NULL)
        return;
    
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void deleteBack(LinkedList* list) {
    if (list->head == NULL)
        return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }
    
    Node *current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

Node* search(LinkedList* list, int target) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data == target)
            return current;
        current = current->next;
    }
    return NULL;
}

void printList(const LinkedList* list) {
    Node* current = list->head;

    if (current == NULL) {
        printf("[ HEAD | NULL ] ");
        return;
    }
    
    printf("[ HEAD | * ] => ");

    while (current != NULL)
    {
        if (current->next != NULL)
            printf("[ %2d | * ] => ", current->data);
        else
            printf("[ %2d | NULL ]", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(LinkedList* list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}