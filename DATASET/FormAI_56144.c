//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

/* Define the struct for the linked list node */
typedef struct Node {
    int value;
    struct Node* next;
} Node;

/* Function to create a new node */
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/* Function to insert a node at the beginning of the linked list */
void insertAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

/* Function to insert a node at the end of the linked list */
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

/* Function to delete a node with a given value */
void deleteNode(Node** head, int value) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr != NULL && curr->value != value) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Node not found\n");
    } else if (prev == NULL) {
        *head = curr->next;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

/* Function to print the linked list */
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

/* Main function to test the linked list operations */
int main() {
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    return 0;
}