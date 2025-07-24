//FormAI DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Declare a structure named "Node"
typedef struct Node {
    int data;
    struct Node *next;  // Pointer to the next node
} Node;

// Function to create a new node with a given data value
Node *createNewNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNewNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
    if (*head == NULL) {
        *head = createNewNode(data);
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNewNode(data);
}

// Function to delete a node with a given data value
void deleteNode(Node **head, int data) {
    Node *current = *head;
    Node *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found\n", data);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Function to print the list
void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;  // Declare an empty list

    // Insert nodes into the list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Print the list before deleting any node
    printf("List before deleting any node: ");
    printList(head);

    // Delete a node with a given value
    deleteNode(&head, 3);

    // Print the list after deleting a node
    printf("List after deleting a node: ");
    printList(head);

    // Insert a node at the beginning of the list
    insertAtBeginning(&head, 0);

    // Print the list after inserting a node at the beginning
    printf("List after inserting a node at the beginning: ");
    printList(head);

    return 0;
}