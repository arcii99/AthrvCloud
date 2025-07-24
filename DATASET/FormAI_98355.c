//FormAI DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

// Defining the structure of the node
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node **head_ref, int new_data) {
    // Allocate memory to the new node
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    // Set the next of this new node to the previous head
    new_node->next = (*head_ref);
    // Set the head to the new node
    (*head_ref) = new_node;
}

// Function to insert a node after a given node
void insertAfter(struct Node *prev_node, int new_data) {
    if(prev_node == NULL) {
        printf("Previous node cannot be NULL");
        return;
    }
    // Allocate memory to the new node
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    // Set the next of this new node to the next of prev_node
    new_node->next = prev_node->next;
    // Set the next of prev_node to the new node
    prev_node->next = new_node;
}

// Function to insert a node at the end
void insertAtEnd(struct Node **head_ref, int new_data) {
    // Allocate memory to the new node
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    // Set the next of this new node to NULL
    new_node->next = NULL;
    // If the linked list is empty, make this new node the head
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // Traverse till the last node
    while(last->next != NULL) {
        last = last->next;
    }
    // Set the next of last node to the new node
    last->next = new_node;
    return;
}

// Function to delete a node with given key
void deleteNode(struct Node **head_ref, int key) {
    // Store the head node
    struct Node *temp = *head_ref, *prev;
    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Traverse through the linked list to find the key to be deleted
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    // If the key was not present in the linked list
    if(temp == NULL) {
        printf("Key not found");
        return;
    }
    // Unlink the node with the given key
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node *node) {
    // Traverse through the linked list till the last node
    while(node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}

// Driver Program
int main() {
    struct Node *head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    insertAfter(head->next, 7);
    printf("Linked List: ");
    displayList(head);
    deleteNode(&head, 5);
    printf("\nLinked List after deletion: ");
    displayList(head);
    return 0;
}