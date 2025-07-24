//FormAI DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Struct for creating a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;

    while(temp != NULL)  {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    // Create the linked list with some data
    struct Node* head = NULL;
    head = insertNode(head, 7);
    head = insertNode(head, 15);
    head = insertNode(head, 3);
    head = insertNode(head, 10);

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    return 0;
}