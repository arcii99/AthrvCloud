//FormAI DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Definition of a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node at the beginning of the linked list
struct Node* add_node_at_beginning(struct Node* head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to print the contents of the linked list
void print_list(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty!");
        return;
    }
    struct Node* current = head;
    printf("Linked List: ");
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating an empty linked list
    struct Node* head = NULL;
    
    // Adding nodes to the linked list
    head = add_node_at_beginning(head, 5);
    head = add_node_at_beginning(head, 9);
    head = add_node_at_beginning(head, 2);
    head = add_node_at_beginning(head, 4);
    
    // Printing the linked list
    print_list(head);
    
    return 0;
}