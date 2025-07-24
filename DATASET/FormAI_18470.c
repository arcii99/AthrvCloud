//FormAI DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList *createList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addToList(LinkedList *list, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
    printf("Added %d to the list.\n", val);
}

void removeFromList(LinkedList *list, int val) {
    if (list->head == NULL) {
        printf("List is empty.\n");
    }
    else if (list->head->val == val) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        printf("Removed %d from the list.\n", val);
    }
    else {
        Node *current = list->head;
        while (current->next != NULL && current->next->val != val) {
            current = current->next;
        }
        if (current->next == NULL) {
            printf("%d not found in the list.\n", val);
        }
        else {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            list->size--;
            printf("Removed %d from the list.\n", val);
        }
    }
}

void printList(LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
    }
    else {
        printf("Current list: ");
        Node *current = list->head;
        while (current != NULL) {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    LinkedList *list = createList();
    addToList(list, 10);
    addToList(list, 20);
    addToList(list, 30);
    addToList(list, 40);
    printList(list);
    removeFromList(list, 20);
    printList(list);
    removeFromList(list, 50);
    printList(list);
    return 0;
}