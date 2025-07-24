//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>   // Standard Input Output Header File
#include <stdlib.h>  // Standard Library Header File

// Defining a node structure of a singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create and initialize a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = data;                        // Set the data of the new node
    newNode->next = NULL;                        // Initialize the next node to NULL
    return newNode;
}

// Function to add a new node to the beginning of the list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data); // Create a new node
    newNode->next = head;             // Set the next node of the new node to the head
    head = newNode;                   // Set the head to the new node
    return head;                      // Return the updated head
}

// Function to display the linked list
void displayList(Node* head) {
    printf("Linked List: ");
    while(head != NULL) {
        printf("%d -> ", head->data); // Print the data of the current node
        head = head->next;            // Move to the next node
    }
    printf("NULL\n");                 // Print NULL at the end of the list
}

int main() {
    Node* head = NULL;                   // Initialize the head of the list to NULL
    head = insertAtBeginning(head, 5);   // Add a new node with data 5 at the beginning of the list
    head = insertAtBeginning(head, 10);  // Add a new node with data 10 at the beginning of the list
    head = insertAtBeginning(head, 15);  // Add a new node with data 15 at the beginning of the list
    displayList(head);                   // Display the final list

    return 0; // Return 0 to indicate successful execution of the program
}