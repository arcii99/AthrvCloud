//FormAI DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the function to insert a node at the beginning of the list
void insertAtBegin(struct Node** headRef, int newData) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // Set the data and next pointer for the new node
    newNode->data = newData;
    newNode->next = (*headRef);
    
    // Set the head to the new node
    (*headRef) = newNode;
}

// Define the function to print the list
void printList(struct Node* node) {
    // Loop through the list and print each node
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Define the main function
int main() {
    // Create a new head node and insert some values
    struct Node* head = NULL;
    insertAtBegin(&head, 4);
    insertAtBegin(&head, 2);
    insertAtBegin(&head, 6);
    insertAtBegin(&head, 8);
    insertAtBegin(&head, 1);
    
    // Print the list
    printf("The list is: ");
    printList(head);
    printf("\n");
    
    // Return 0 to indicate success
    return 0;
}