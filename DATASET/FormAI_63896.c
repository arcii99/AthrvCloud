//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Defining the node of the linked list
struct node {
    int value;
    struct node *next;
};

// Function to create a new linked list node
struct node *new_node(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

// Function to add a node to the linked list
void add_node(struct node **head_ref, int value) {
    struct node *temp = new_node(value);
    if (*head_ref == NULL) {
        *head_ref = temp;
        return;
    }
    struct node *curr_node = *head_ref;
    while (curr_node->next != NULL)
        curr_node = curr_node->next;
    curr_node->next = temp;
}

// Function to print the linked list
void print_list(struct node *head) {
    printf("Linked List:\n");
    struct node *curr_node = head;
    while (curr_node != NULL) {
        printf("%d ", curr_node->value);
        curr_node = curr_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node *head = NULL;

    // Adding nodes to the linked list
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    add_node(&head, 40);
    add_node(&head, 50);

    // Printing the linked list
    print_list(head);

    return 0;
}