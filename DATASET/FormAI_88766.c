//FormAI DATASET v1.0 Category: Data structures visualization ; Style: active
#include<stdio.h>

// A structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    // Creating a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    // Adding data to newNode
    newNode->data = data;
    // Updating the next of newNode
    newNode->next = (*head);
    // Updating head
    (*head) = newNode;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    // Traversing the linked list
    while(head != NULL) {
        // Printing the data of the node
        printf("%d ", head->data);
        // Moving to the next node
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Creating an empty linked list
    struct Node* head = NULL;

    // Inserting some nodes at the beginning of the linked list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Printing the linked list
    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}