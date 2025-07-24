//FormAI DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

// Node structure for linked list
struct node {
    int value;
    struct node* next;
};

// Function to add a node at the beginning of the list
void push(struct node** head_ref, int value) {
    // Create a new node and allocate memory
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    // Assign value to the node
    new_node->value = value;
    // Assign next to the node
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

// Function to add a node after a specific node
void insert_after(struct node* prev_node, int value) {
    // If previous node is null, return
    if(prev_node == NULL) {
        printf("Error: Previous node cannot be null\n");
        return;
    }
    // Create a new node and allocate memory
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    // Assign value to the node
    new_node->value = value;
    // Assign next to the node
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

// Function to add a node at the end of the list
void append(struct node** head_ref, int value) {
    // Create a new node and allocate memory
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref;
    // Assign value to the node
    new_node->value = value;
    // Assign next to the node
    new_node->next = NULL;

    // If the list is empty, make the new node as head
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to delete a node with given key
void delete_node(struct node** head_ref, int key) {
    // Store head node
    struct node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->value == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while(temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if(temp == NULL) {
        printf("Error: Key not found in linked list\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free up the memory
    free(temp);
}

// Function to traverse and print the linked list
void print_list(struct node* node) {
    while(node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
}

// Main function
int main() {
    struct node* head = NULL;

    // Insert 5 at the beginning of the linked list
    push(&head, 5);
    // Insert 4 after the first node
    insert_after(head, 4);
    // Add 2 at the end of the linked list
    append(&head, 2);
    // Delete the node with the value 4
    delete_node(&head, 4);

    printf("Linked list: ");
    print_list(head);

    return 0;
}