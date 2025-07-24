//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push a new node onto the linked list
void push(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set data for new node and set next to current head
    new_node->data = new_data;
    new_node->next = (*head_ref);
    // Set new node as head
    (*head_ref) = new_node;
}

// Function to insert a new node after a given node
void insert_after(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Given previous node cannot be NULL\n");
        return;
    }
    // Allocate memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set data for new node and set next to the next of previous node
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to append a new node to the end of the linked list
void append(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Set data for new node and set next to NULL since it is now the last node
    new_node->data = new_data;
    new_node->next = NULL;
    // If list is empty, set new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // Traverse to the last node and set it's next to the new node
    struct Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Function to delete a node with the given key from the linked list
void delete_node(struct Node** head_ref, int key) {
    // Check if head node needs to be deleted
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Traverse the linked list to find node with key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    // If node with key is not found, return
    if (temp == NULL) {
        return;
    }
    // Remove node with key
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list elements
void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function to test the linked list functions
int main() {
    struct Node* head = NULL;

    printf("Welcome to the linked list visualization program!\n\n");

    printf("Let's start by adding some elements to our list...\n");
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    append(&head, 4);
    insert_after(head->next, 5);
    printf("Our list now contains: ");
    print_list(head);
    printf("\n\n");

    printf("Now let's delete an element from our list...\n");
    delete_node(&head, 3);
    printf("After deleting the element '3', our list contains: ");
    print_list(head);
    printf("\n\n");

    printf("Thank you for using the linked list visualization program!\n");
    return 0;
}