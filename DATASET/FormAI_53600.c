//FormAI DATASET v1.0 Category: Linked list operations ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Define the structure of each node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a function to print all the elements in the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Define a function to insert a new node at the front of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Define a function to delete a node from the linked list with a given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

// Define the main function to create, modify, and print the linked list
int main() {
    struct Node* head = NULL;

    // Add some nodes to the linked list
    push(&head, 4);
    push(&head, 5);
    push(&head, 1);
    push(&head, 9);

    printf("Linked list before deletion: ");
    printList(head);

    // Delete node with key value 5 from the linked list
    deleteNode(&head, 5);

    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}