//FormAI DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // creating new node
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // exit the program with failure
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data); // create new node and insert it at beginning
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertAtEnd(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) { // if list is empty
        *headRef = newNode;
        return;
    }
    Node* currentNode = *headRef;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode; // insert new node at end of list
}

void deleteNode(Node** headRef, int data) {
    Node* currentNode = *headRef;
    Node* previousNode = NULL;
    while (currentNode != NULL && currentNode->data != data) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("Node not found in list!\n");
        return;
    }
    if (previousNode == NULL) { // if head node is to be deleted
        *headRef = currentNode->next;
    } else {
        previousNode->next = currentNode->next; // delete node from list
    }
    free(currentNode); // free memory
}

void displayList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data); // display data of each node
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 7);
    insertAtBeginning(&head, 1);
    displayList(head); // output: 1 3 5 7
    deleteNode(&head, 5);
    displayList(head); // output: 1 3 7
    deleteNode(&head, 2); // output: Node not found in list!
    return 0;
}