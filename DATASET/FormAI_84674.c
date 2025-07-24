//FormAI DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>

/* Define a struct for a node */
typedef struct Node {
    int value;
    struct Node* next;
} Node;

/* Define a struct for a linked list */
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

/* Create a new LinkedList instance */
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

/* Insert a new node with the given value at the end of the list */
void insertAtEnd(LinkedList* list, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* currNode = list->head;
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    list->size++;
}

/* Print the contents of the linked list */
void printLinkedList(LinkedList* list) {
    Node* currNode = list->head;
    while (currNode != NULL) {
        printf("%d -> ", currNode->value);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList* list = createLinkedList();

    /* Insert some values into the list */
    insertAtEnd(list, 5);
    insertAtEnd(list, 10);
    insertAtEnd(list, 15);
    insertAtEnd(list, 20);

    /* Print the contents of the list */
    printLinkedList(list);

    return 0;
}