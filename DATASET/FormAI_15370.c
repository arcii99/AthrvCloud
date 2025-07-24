//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} node_t;

// Define a function to add a new node to the head of the linked list
void insertAtStart(node_t** head, int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Define a function to add a new node to the end of the linked list
void insertAtEnd(node_t** head, int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    node_t* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    
    lastNode->next = newNode;
}

// Define a function to delete a node from the linked list with a given value
void deleteNode(node_t** head, int data) {
    node_t* currNode = *head;
    node_t* prevNode = NULL;
    
    // If the head node contains the value to delete
    if (currNode != NULL && currNode->data == data) {
        *head = currNode->next;
        free(currNode);
        return;
    }
    
    // Traverse the linked list to find the node to delete
    while (currNode != NULL && currNode->data != data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    // If the node to delete is found, update the links and free the memory
    if (currNode != NULL) {
        prevNode->next = currNode->next;
        free(currNode);
    }
}

// Define a function to print the contents of the linked list
void printList(node_t* head) {
    node_t* currNode = head;
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
}

// Define the main function to test the linked list operations
int main() {
    node_t* head = NULL;  // Instantiate an empty linked list
    
    insertAtStart(&head, 5);  // Add nodes to the linked list
    insertAtStart(&head, 3);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);
    printList(head);  // Print the contents of the linked list: 3 5 7 9
    
    deleteNode(&head, 5);  // Delete a node from the linked list
    printList(head);  // Print the contents of the linked list: 3 7 9
    
    return 0;
}