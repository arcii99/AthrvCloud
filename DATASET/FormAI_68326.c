//FormAI DATASET v1.0 Category: Data structures visualization ; Style: grateful
#include <stdio.h>

// Define a node struct for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the end of a linked list
void append(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    // Set the data for the new node
    new_node->data = new_data;
    
    // Set the next pointer for the new node to NULL since it will be the last node
    new_node->next = NULL;
    
    // Check if the linked list is empty
    if (*head_ref == NULL) {
        // If it is, set the head pointer to the new node
        *head_ref = new_node;
        return;
    }
    
    // Otherwise, traverse to the end of the linked list and append the new node
    struct Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Function to print the linked list
void print_list(struct Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct Node* current_node = head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create an empty linked list
    struct Node* head = NULL;
    
    // Append some nodes to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    
    // Print the linked list
    print_list(head);
    
    return 0;
}