//FormAI DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the linked list structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    Node* current = *head_ref;
    if (current == NULL) {
        *head_ref = new_node;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Delete the first occurrence of the given data from the linked list
void delete_node(Node** head_ref, int data) {
    Node* current = *head_ref;
    Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (previous == NULL) {
        *head_ref = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

// Print the linked list
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    Node* head = NULL;
    insert_at_beginning(&head, 5);
    insert_at_end(&head, 10);
    insert_at_beginning(&head, 3);
    insert_at_end(&head, 15);
    printf("Original list: ");
    print_list(head);
    delete_node(&head, 10);
    printf("List after deleting 10: ");
    print_list(head);
    delete_node(&head, 3);
    printf("List after deleting 3: ");
    print_list(head);
    return 0;
}