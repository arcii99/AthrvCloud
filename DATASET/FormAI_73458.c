//FormAI DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for a linked list
typedef struct linked_list {
    Node* head;
} LinkedList;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning
void insertBeginning(LinkedList* list, int value) {
    Node* newNode = createNode(value);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to insert a new node at the end
void insertEnd(LinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    Node* currentNode = list->head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// Function to delete the first occurrence of a node with a given value
void deleteNode(LinkedList* list, int value) {
    Node* currentNode = list->head;
    Node* previousNode = NULL;
    while (currentNode != NULL && currentNode->data != value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        return;
    }
    if (previousNode == NULL) {
        list->head = currentNode->next;
    } else {
        previousNode->next = currentNode->next;
    }
    free(currentNode);
}

// Function to print the linked list
void displayList(LinkedList* list) {
    Node* currentNode = list->head;
    printf("Linked List: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    LinkedList list = { NULL };
    insertEnd(&list, 5);
    insertEnd(&list, 10);
    insertBeginning(&list, 2);
    insertBeginning(&list, 1);
    insertEnd(&list, 15);
    displayList(&list);
    deleteNode(&list, 2);
    deleteNode(&list, 15);
    deleteNode(&list, 20);
    displayList(&list);
    return 0;
}