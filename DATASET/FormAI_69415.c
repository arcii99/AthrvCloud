//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Defining a Node structure to hold data and next pointer
struct Node {
    int data;
    struct Node* next;
};

// Function to insert new nodes at the beginning of the list
void insertAtBeginning(struct Node** headRef, int newData) {
    // Creating a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Adding data to the new node
    newNode->data = newData;
    // Pointing the new node to the beginning of the list
    newNode->next = *headRef;
    // Pointing the head to the new node (as it is now the first node)
    *headRef = newNode;
}

// Function to insert new nodes at the end of the list
void insertAtEnd(struct Node** headRef, int newData) {
    // Creating a new node and pointing it to NULL (as it will be the last node)
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    // If the list is empty, point the head to the new node
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    // Traversing to the last node of the list
    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    // Pointing the last node's next pointer to the new node
    lastNode->next = newNode;
}

// Function to delete nodes from the list
void deleteNode(struct Node** headRef, int key) {
    // Temp pointers to traverse the list and hold reference to the previous node
    struct Node* currentNode = *headRef;
    struct Node* prevNode = NULL;
    // If the head node itself holds the key to be deleted
    if (currentNode != NULL && currentNode->data == key) {
        *headRef = currentNode->next; // Changed head
        free(currentNode); // Free old head
        return;
    }
    // Traversing to the node which holds the key to be deleted
    while (currentNode != NULL && currentNode->data != key) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    // If key is not present in the list
    if (currentNode == NULL) {
        return;
    }
    // Unlinking the node containing the key to be deleted
    prevNode->next = currentNode->next;
    free(currentNode); // Free memory
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver code to test the implementation
int main() {

    // Initially list is empty
    struct Node* head = NULL;

    // Inserting a few nodes at the beginning of the list
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);

    // Inserting a few nodes at the end of the list
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 13);

    // Printing the list
    printf("\nLinked List: ");
    printList(head);

    // Deleting a node from the list
    printf("\nDeleting node 5 from the list\n");
    deleteNode(&head, 5);

    // Printing the list after deletion
    printf("\nLinked List after deletion: ");
    printList(head);

    return 0;
}