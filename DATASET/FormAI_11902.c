//FormAI DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure named "Node"
typedef struct {
    int value;
    struct Node* next;
} Node;

// Define a function to create a new node with a given value
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Define a function to add a new node to the end of the linked list
void appendNode(Node** headRef, int value) {
    Node* newNode = createNode(value); // Create a new node with the given value

    if (*headRef == NULL) { // If the linked list is empty
        *headRef = newNode; // Set the head of the linked list to the new node
        return;
    }

    Node* lastNode = *headRef;
    while (lastNode->next != NULL) { // Traverse the linked list to find the last node
        lastNode = lastNode->next;
    }

    lastNode->next = newNode; // Add the new node to the end of the linked list
}

// Define a function to print the contents of the linked list
void printList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    appendNode(&head, 1); // Add nodes to the linked list
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printList(head); // Print the contents of the linked list

    return 0;
}