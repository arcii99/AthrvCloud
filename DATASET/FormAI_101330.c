//FormAI DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// define the node structure for our linked list
struct Node {
    int data;
    struct Node* next;
};

// declare a function to create a new Node with a given data value
struct Node* createNode(int dataValue) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = dataValue;
    newNode->next = NULL;
    return newNode;
}

// declare a function to insert a new Node at the end of the linked list
void insertNode(struct Node** headRef, int dataValue) {
    // create the new Node with the data value
    struct Node* newNode = createNode(dataValue);
    // if the linked list is empty, make the new Node the head
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    // otherwise, traverse to the end of the linked list and insert the new Node
    struct Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// declare a function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // initialize an empty linked list
    struct Node* head = NULL;
    // insert some nodes into the linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    // print the linked list
    printf("The linked list contains: ");
    printList(head);
    // free the memory allocated for the linked list nodes
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    // set the head to NULL to indicate an empty linked list
    head = NULL;
    return 0;
}