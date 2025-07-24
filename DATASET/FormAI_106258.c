//FormAI DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

/* Define a struct representing a linked list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to add a new node at the beginning of the linked list */
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to add a new node after a given node */
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL'");
        return;
    }
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/* Function to add a new node at the end of the linked list */
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

/* Function to delete a node with the given key */
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("The element does not exist in the linked list");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

/* Function to traverse and print the linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Main program to test the above linked list operations */
int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    printf("Original Linked List: ");
    printList(head);
    deleteNode(&head, 1);
    printf("\nLinked List after deletion of 1: ");
    printList(head);
    return 0;
}