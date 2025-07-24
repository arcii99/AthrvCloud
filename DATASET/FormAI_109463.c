//FormAI DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a struct for our custom data type
typedef struct {
    int data;
    struct Node* next;
} Node;

// Define function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define function to insert a node at the front of the linked list
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data); // create a new node with the data
    newNode->next = (*head); // point the new node's next to the current head
    (*head) = newNode; // set the new node as the head
}

// Define a function to print the linked list
void printLinkedList(Node* head) {
    Node* currentNode = head; // start at the head node
    while (currentNode != NULL) { // loop through each node until we reach the end
        printf("%d ", currentNode->data); // print the data
        currentNode = currentNode->next; // set the current node to the next node
    }
    printf("\n"); // print a newline character at the end
}

// main function to test our data structure
int main() {
    Node* head = NULL; // initialize the head node to NULL

    insertAtFront(&head, 1); // insert 1 at the front of the linked list
    insertAtFront(&head, 2); // insert 2 at the front of the linked list
    insertAtFront(&head, 3); // insert 3 at the front of the linked list
    insertAtFront(&head, 4); // insert 4 at the front of the linked list

    printf("The linked list is: ");
    printLinkedList(head); // print the linked list

    return 0;
}