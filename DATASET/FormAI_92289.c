//FormAI DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Creates a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Inserts a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

// Traverses the linked list and prints the data of each node
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    
    // Insert nodes in the linked list
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the contents of the linked list
    printf("The linked list contains: ");
    printList(head);
    
    return 0;
}