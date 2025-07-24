//FormAI DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert a new node at the beginning of linked list
void insertNode(Node **head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = (*head);
    (*head) = newNode;
}

// Display the entire linked list
void displayList(Node *head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes to the beginning of the list
    insertNode(&head, 5);
    insertNode(&head, 3);
    insertNode(&head, 7);
    insertNode(&head, 2);

    // Display the entire list
    displayList(head);

    return 0;
}