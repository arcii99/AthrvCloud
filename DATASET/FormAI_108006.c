//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
} List;

List* createList() {
    List* newList = malloc(sizeof(List));
    newList->head = NULL;
    return newList;
}

void addNode(List* list, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
}

void printList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List* myList = createList();
    addNode(myList, 5);
    addNode(myList, 10);
    addNode(myList, 15);
    addNode(myList, 20);
    addNode(myList, 25);
    printf("My List: ");
    printList(myList);
    return 0;
}