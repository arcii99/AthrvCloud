//FormAI DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert a new node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Insert a new node after the given prev_node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be null");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Append a new node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Used to traverse the list

    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;
}

// Delete the first occurrence of a key in the linked list
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Traverse through the linked list and find the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key is not present in the linked list
    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert new nodes at the beginning of the list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Linked list after inserting 5 nodes at the beginning:\n");
    printList(head);

    // Insert a node after the second node in the list
    insertAfter(head->next, 6);
    printf("Linked list after inserting a node after the second node:\n");
    printList(head);

    // Append a node at the end of the list
    append(&head, 7);
    append(&head, 8);
    append(&head, 9);
    printf("Linked list after appending 3 nodes at the end:\n");
    printList(head); 

    // Delete a node from the list
    deleteNode(&head, 3);
    printf("Linked list after deleting node with value 3:\n");
    printList(head);

    return 0;
}