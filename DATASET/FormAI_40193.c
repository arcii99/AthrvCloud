//FormAI DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertRear(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prevNode;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prevNode = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prevNode->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    insertRear(&head, 10);
    insertFront(&head, 20);
    insertRear(&head, 30);
    insertFront(&head, 40);
    printf("Linked list: ");
    printList(head);
    deleteNode(&head, 10);
    deleteNode(&head, 40);
    printf("\nAfter deleting: ");
    printList(head);
    return 0;
}