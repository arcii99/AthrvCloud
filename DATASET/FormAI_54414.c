//FormAI DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the linked list
typedef struct List {
    Node* head;
    int size;
} List;

// Initialize a new list
List* createList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Insert an element at the beginning of the list
void insertFirst(List* list, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Insert an element at the end of the list
void insertLast(List* list, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }

    list->size++;
}

// Insert an element at a specific position in the list
void insertAt(List* list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }

    if (position == 0) {
        insertFirst(list, data);
    } else if (position == list->size) {
        insertLast(list, data);
    } else {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;

        Node* current = list->head;
        int i;

        for (i = 0; i < position-1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        list->size++;
    }
}

// Remove the first element from the list
void removeFirst(List* list) {
    if (list->head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);

    list->size--;
}

// Remove the last element from the list
void removeLast(List* list) {
    if (list->head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        free(current->next);
        current->next = NULL;
    }

    list->size--;
}

// Remove the element at a specific position in the list
void removeAt(List* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }

    if (position == 0) {
        removeFirst(list);
    } else if (position == list->size-1) {
        removeLast(list);
    } else {
        Node* current = list->head;
        int i;

        for (i = 0; i < position-1; i++) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);

        list->size--;
    }
}

// Print the elements in the list
void printList(List* list) {
    Node* current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    List* list = createList();
    insertLast(list, 1);
    insertFirst(list, 2);
    insertAt(list, 3, 1);
    insertLast(list, 4);
    removeAt(list, 1);
    printList(list);
    removeLast(list);
    removeFirst(list);
    printList(list);
    return 0;
}