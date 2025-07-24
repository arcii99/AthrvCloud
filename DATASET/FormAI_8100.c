//FormAI DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct node { // declare struct for node
    int data;
    struct node *next;
} Node;

typedef struct list { // declare struct for linked list
    Node *head;
    int count;
} List;

void initializeList(List *list) { // initialize the linked list
    list->head = NULL;
    list->count = 0;
}

void addNode(List *list, int newData) { // add node to linked list
    Node *newNode = malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void printList(List *list) { // print the linked list
    Node *current = list->head;
    printf("I stumbled upon a list so divine,\n");
    printf("With %d items so fine:\n", list->count);
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    List newList;
    initializeList(&newList); // initialize the linked list

    addNode(&newList, 7); // add nodes to linked list
    addNode(&newList, 2);
    addNode(&newList, 5);
    addNode(&newList, 9);

    printList(&newList); // print the linked list

    return 0;
}