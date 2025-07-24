//FormAI DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

Node* newNode(char* data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = (char*) malloc(strlen(data) + 1);
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

void insert(Node** head, char* data) {
    Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%s --> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insert(&head, "Hello");
    insert(&head, "World");
    insert(&head, "This");
    insert(&head, "Is");
    insert(&head, "A");
    insert(&head, "Linked");
    insert(&head, "List");
    printf("Original List:\n");
    printList(head);

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = (char*) malloc(strlen("Mind-Bending Node") + 1);
    strcpy(newNode->data, "Mind-Bending Node");
    newNode->next = head->next->next;
    head->next->next = newNode;
    printf("\nAfter Insertion:\n");
    printList(head);

    return 0;
}