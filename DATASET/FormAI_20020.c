//FormAI DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct node { // Define the node structure
    int data; // Data to be stored in the node
    struct node* next; // Pointer to the next node
};

int main() {
    int n, i; // Declare variables n for number of nodes and i for loop counter
    printf("Enter the number of nodes: ");
    scanf("%d", &n); // Take input for number of nodes to create

    // Create the linked list
    struct node* head = (struct node*) malloc(sizeof(struct node)); // Allocate memory for the head node
    printf("Enter data for node 1: ");
    scanf("%d", &head->data); // Take input for head node data
    head->next = NULL; // Set the next pointer to NULL

    struct node* current = head; // Create a temporary pointer to the current node

    for (i = 2; i <= n; i++) { // Loop through to create all the nodes
        struct node* new_node = (struct node*) malloc(sizeof(struct node)); // Allocate memory for the new node
        printf("Enter data for node %d: ", i);
        scanf("%d", &new_node->data); // Take input for the new node data
        new_node->next = NULL; // Set the next pointer to NULL
        current->next = new_node; // Set the current node's next pointer to the new node
        current = new_node; // Set the current pointer to the new node
    }

    // Visualize the linked list
    printf("The linked list is: ");
    current = head; // Reset the current pointer to the head node

    printf("HEAD -> "); // Visualize the head node
    while (current != NULL) { // Loop through all the nodes until the end of the list is reached
        printf("%d", current->data); // Print the data in the current node
        if (current->next != NULL) { // Check if there is a next node
            printf(" -> "); // Visualize the arrow between nodes
        }
        current = current->next; // Move the current pointer to the next node
    }
    printf(" -> NULL"); // Visualize the null pointer at the end of the list
    return 0;
}