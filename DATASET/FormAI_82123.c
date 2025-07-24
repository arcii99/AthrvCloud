//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printLinkedList(struct node *head) {
    struct node *current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertNode(struct node **headRef, int newData) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

int main() {
    struct node *head = NULL;

    // Insert nodes into the linked list
    insertNode(&head, 5);
    insertNode(&head, 3);
    insertNode(&head, 7);
    insertNode(&head, 1);
    insertNode(&head, 9);

    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}