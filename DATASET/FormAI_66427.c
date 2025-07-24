//FormAI DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// define a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to add a node at the end of the list
void addNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        // if list is empty, set new node as head
        *headRef = newNode;
    } else {
        // otherwise, traverse to the end of the list and add node
        Node* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// function to print the list
void printList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// main function
int main() {
    Node* myList = NULL;
    addNode(&myList, 1);
    addNode(&myList, 2);
    addNode(&myList, 3);
    printList(myList);
    return 0;
}