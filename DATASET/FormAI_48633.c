//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the futuristic data structure
struct node {
    int data;
    struct node* next;
};

// Define a function to insert a node at the beginning of the list
void insert(struct node** head, int data) {
    // Create a new node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    // Update the head pointer to point to the new node
    *head = new_node;
}

// Define a function to print the nodes in the list
void display(struct node* head) {
    struct node* current_node = head;
    while (current_node != NULL) {
        printf("\t\t\t\t\t\t\t\t\t   %d\n", current_node->data);
        current_node = current_node->next;
    }
}

int main() {
    // Define the head node and insert some nodes into the list
    struct node* head = NULL;
    insert(&head, 9);
    insert(&head, 12);
    insert(&head, 5);
    
    // Print out the nodes in a futuristic way
    printf("\t\t\t\t\t\t\t\t ___  ___  ___  ___  ___  ___.________\n");
    printf("\t\t\t\t\t\t\t\t|   \\/   \\/   \\/   \\/   \\/   |   ____/\n");
    printf("\t\t\t\t\t\t\t\t|   \\        /\\        /    |____  \\ \n");
    printf("\t\t\t\t\t\t\t\t|   /\\      /\\ \\      / /\\  /       \\\n");
    printf("\t\t\t\t\t\t\t\t|__/  \\____/   \\____/ /__/ /________/\n");
    display(head);
    printf("\n");
    return 0;
}