//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    printf("HEAD --> ");

    while (head != NULL) {
        printf("%d --> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

int main() {
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Initial Linked List:\n");
    printList(head);

    struct Node* temp = head->next->next;
    head->next->next = head->next->next->next;
    free(temp);

    printf("\nLinked List after deleting the node with value 3:\n");
    printList(head);

    return 0;
}