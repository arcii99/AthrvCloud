//FormAI DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// create a struct for the linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// create a function to add a new node to the front of the linked list
void push(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// create a function to add a new node after a specified node
void insertAfter(Node* prev_node, int new_data) {
    if(prev_node == NULL) {
        printf("The given previous node cannot be NULL.");
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// create a function to append a new node to the end of the linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// create a function to delete a node with a specified value from the linked list
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev;
    if(temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// create a function to print the linked list
void printList(Node* node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// create a main function to test out the linked list functions
int main() {
    Node* head = NULL;

    // add nodes to the linked list
    append(&head, 1);
    push(&head, 2);
    push(&head, 3);
    insertAfter(head->next, 4);

    // print the linked list
    printf("Linked list: ");
    printList(head);

    // delete a node from the linked list
    deleteNode(&head, 3);

    // print the linked list again
    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}