//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the email address and the name
#define MAX_LENGTH 100

// Define the node struct
typedef struct node {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    struct node* next;
} node_t;

// Define the head of the list
node_t* head = NULL;

// Function to add a new node to the list
void add_node(char* name, char* email) {
    // Create a new node
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    // Copy the name and email to the new node
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);

    // Set the next of the new node to the current head of the list
    new_node->next = head;

    // Set the new node to be the new head of the list
    head = new_node;
}

// Function to remove a node from the list
void remove_node(char* email) {
    // Set two pointers to traverse the list (prev and curr)
    node_t* prev_node = NULL;
    node_t* curr_node = head;

    // Traverse the list
    while (curr_node != NULL) {
        // If the email matches, remove the node
        if (strcmp(curr_node->email, email) == 0) {
            if (prev_node == NULL) {
                // If the node to remove is the head of the list, set the next node as the new head
                head = curr_node->next;
            } else {
                // Otherwise, set the next of the previous node to the next of the current node
                prev_node->next = curr_node->next;
            }

            // Free the memory allocated to the node
            free(curr_node);

            // Exit the function
            return;
        }

        // Move the pointers to the next nodes
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}

// Function to print the list
void print_list() {
    // Set a pointer to traverse the list
    node_t* curr_node = head;

    // Traverse the list and print the data in each node
    while (curr_node != NULL) {
        printf("%s <%s>\n", curr_node->name, curr_node->email);
        curr_node = curr_node->next;
    }
}

int main() {
    // Add some example nodes to the list
    add_node("John Doe", "john.doe@example.com");
    add_node("Jane Doe", "jane.doe@example.com");
    add_node("Bob Smith", "bob.smith@example.com");

    // Print the list
    printf("Mailing list:\n");
    print_list();

    // Remove a node from the list
    remove_node("jane.doe@example.com");

    // Print the updated list
    printf("\nUpdated mailing list:\n");
    print_list();

    return 0;
}