//FormAI DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertBack(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* current = *headRef;
    if (current == NULL) {
        *headRef = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node** headRef, int data) {
    Node* current = *headRef;
    Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found in the list\n");
        return;
    }
    if (previous == NULL) {
        *headRef = current->next;
    }
    else {
        previous->next = current->next;
    }
    free(current);
}

void displayList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertFront(&head, 3);
    insertFront(&head, 2);
    insertFront(&head, 1);
    displayList(head);
    insertBack(&head, 4);
    displayList(head);
    deleteNode(&head, 3);
    displayList(head);
    return 0;
}