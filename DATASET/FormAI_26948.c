//FormAI DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
/* Post-Apocalyptic Linked List Operations */
#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data; // Data stored in the node
    struct Node* next; // Pointer to next node
};

// Function to create a new node
struct Node* createNode(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of a linked list
void append(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to delete a node at a given index in the linked list
void deleteAtIndex(struct Node** headRef, int index) {
    if (*headRef == NULL)
        return;
    struct Node* currentNode = *headRef;
    if (index == 0) {
        *headRef = currentNode->next;
        free(currentNode);
        return;
    }
    for (int i = 0; currentNode != NULL && i < index - 1; i++) {
        currentNode = currentNode->next;
    }
    if (currentNode == NULL || currentNode->next == NULL)
        return;
    struct Node* nextNode = currentNode->next->next;
    free(currentNode->next);
    currentNode->next = nextNode;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty!");
        return;
    }
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

int main() {
    // Create empty linked list
    struct Node* head = NULL;

    // Add nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    // Display the linked list
    printf("The linked list is: \n");
    display(head);
    printf("\n\n");

    // Delete nodes from the linked list
    deleteAtIndex(&head, 1);
    printf("After deleting node at index 1: \n");
    display(head);
    printf("\n\n");

    deleteAtIndex(&head, 0);
    printf("After deleting node at index 0: \n");
    display(head);
    printf("\n\n");

    deleteAtIndex(&head, 2);
    printf("After attempting to delete node at index 2 (out of bounds): \n");
    display(head);

    return 0;
}