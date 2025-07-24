//FormAI DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// define our struct
struct node {
    int data;
    struct node* next;
};

// function to insert a new node at the beginning of linked list
void insertNode(struct node** head, int data) {
    // allocate memory for new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    // set data of new node
    newNode->data = data;
    // set next of new node to current head
    newNode->next = *head;
    // set head to point to new node
    *head = newNode;
}

// function to print all nodes in linked list
void printList(struct node* head) {
    // loop through all nodes in linked list
    while (head != NULL) {
        // print data of current node
        printf("%d -> ", head->data);
        // move to next node
        head = head->next;
    }
    // print null to indicate end of linked list
    printf("NULL\n");
}

int main() {
    // initialize head of linked list to null
    struct node* head = NULL;
    
    // insert nodes in linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    // print linked list
    printList(head);

    return 0;
}