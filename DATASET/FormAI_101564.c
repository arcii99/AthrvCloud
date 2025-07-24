//FormAI DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// define structure of a linked list node
struct node {
    int data;
    struct node *next;
};

// function to insert new node at the beginning of the linked list
void insertAtBeginning(struct node **head, int data) {
    // create a new node
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    // assign data and point next to current head
    new_node->data = data;
    new_node->next = *head;
    // update head to new node 
    *head = new_node;
}

// function to insert new node at the end of the linked list
void insertAtEnd(struct node **head, int data) {
    // create a new node
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    // assign data and point next to NULL
    new_node->data = data;
    new_node->next = NULL;
    // check if list is empty
    if (*head == NULL) {
        // set head to new node 
        *head = new_node;
        return;
    }
    // traverse to the end of the linked list
    struct node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    // update last node's next to new node 
    last_node->next = new_node;
}

// function to delete a node from the linked list
void deleteNode(struct node **head, int key) {
    // check if list is empty
    if (*head == NULL) {
        return;
    }
    // store head node and previous node
    struct node *current_node = *head, *prev_node;
    // check if head node contains key
    if (current_node->data == key) {
        *head = current_node->next;
        free(current_node);
        return;
    }
    // traverse to find node with key
    while (current_node != NULL && current_node->data != key) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    // if node with key is found, delete it
    if (current_node != NULL) {
        prev_node->next = current_node->next;
        free(current_node);
    }
}

// function to print the linked list
void printLinkedList(struct node *head) {
    // traverse and print each node's data
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// main function to test linked list operations
int main() {
    struct node *head = NULL;
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4);
    printf("Original Linked List: ");
    printLinkedList(head);
    deleteNode(&head, 3);
    printf("Linked List after deleting node with data = 3: ");
    printLinkedList(head);
    return 0;
}