//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10

// Create a struct for a node in our data structure
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Create a struct for our data structure, which will be a linked list
typedef struct LinkedList {
    Node* head;
    int count;
} LinkedList;

// Function to initialize our linked list
void initList(LinkedList* list) {
    list->head = NULL;
    list->count = 0;
}

// Function to add a node to our linked list
void addNode(LinkedList* list, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

// Function to print our linked list
void printList(LinkedList* list) {
    Node* current = list->head;
    printf("Head -> ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Initialize our linked list
    LinkedList list;
    initList(&list);
    
    // Add some random nodes to our linked list
    for (int i = 0; i < SIZE; i++) {
        addNode(&list, rand() % 10);
    }
    
    // Print our linked list
    printList(&list);
    
    return 0;
}