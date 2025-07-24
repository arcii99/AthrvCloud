//FormAI DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
/* Claude Shannon Style C Linked List Operations Example */

#include <stdio.h>
#include <stdlib.h>

// Define linked list node
struct Node {
    int data;
    struct Node* next;
};

// Define function for creating new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define function for inserting new node at the beginning of list
void insertAtBeginning(struct Node** headRef, int data) {
    // Create new node
    struct Node* newNode = createNode(data);
    // Set new node's next to current head
    newNode->next = *headRef;
    // Set current head to new node
    *headRef = newNode;
}

// Define function for inserting new node at the end of list
void insertAtEnd(struct Node** headRef, int data) {
    // Create new node
    struct Node* newNode = createNode(data);
    // Check if list is empty
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    // Traverse to end of list
    struct Node* curr = *headRef;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    // Set last node's next to new node
    curr->next = newNode;
}

// Define function for deleting node by given value
void deleteNode(struct Node** headRef, int data) {
    // Check if head node matches value
    struct Node* curr = *headRef;
    if (curr != NULL && curr->data == data) {
        *headRef = curr->next;
        free(curr);
        return;
    }
    // Traverse through list to find node with match
    struct Node* prev = NULL;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    // If node is not found, return
    if (curr == NULL) {
        return;
    }
    // Delete matched node
    prev->next = curr->next;
    free(curr);
}

// Define function for printing all nodes in list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    // Initialize empty linked list
    struct Node* head = NULL;
    // Insert nodes with values 1, 2, and 3
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    // Print the list
    printf("Initial Linked List: ");
    printList(head);
    printf("\n");
    // Delete node with value 2
    deleteNode(&head, 2);
    // Print the updated list
    printf("Updated Linked List: ");
    printList(head);
    printf("\n");
    return 0;
}