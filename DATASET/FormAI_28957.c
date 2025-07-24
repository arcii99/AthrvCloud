//FormAI DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a single node in a linked list
struct Node {
    int data;           // The data value stored in the node
    struct Node* next;  // The pointer to the next node in the list
};

// Function to create a new node and return a pointer to it
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list (i.e., after the head)
void insert_first(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the list
void insert_last(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    struct Node* current = *head;
    if (*head == NULL) {  // if list is empty
        *head = new_node;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to delete a node from the list
void delete_node(struct Node** head, int data) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    if (current != NULL && current->data == data) {   // if node to be deleted is the head
        *head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {  // if node to be deleted is not found in the list
        return;
    }
    prev->next = current->next;
    free(current);
}

// Function to print all the nodes in the list
void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert a few nodes into the list
    insert_first(&head, 5);
    insert_first(&head, 10);
    insert_last(&head, 15);
    insert_first(&head, 20);

    // Print the nodes in the list
    printf("Initial list: ");
    print_list(head);

    // Delete a few nodes from the list
    delete_node(&head, 10);
    delete_node(&head, 25);  // node with data 25 doesn't exist

    // Print the remaining nodes in the list
    printf("Final list: ");
    print_list(head);

    return 0;
}