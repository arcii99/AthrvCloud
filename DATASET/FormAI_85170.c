//FormAI DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Create a struct for a node in a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add a node to the end of a linked list
void append(Node** headRef, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

// Function to print out the current state of the linked list
void printList(Node* head) {
    printf("Current state of linked list: ");
    Node* currNode = head;
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Add some nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    // Print out the current state of the linked list
    printList(head);

    // Add another node to the linked list
    append(&head, 4);

    // Print out the updated state of the linked list
    printList(head);

    return 0;
}