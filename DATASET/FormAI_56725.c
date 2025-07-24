//FormAI DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void push(struct Node** head, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* node) {
    printf("List: ");
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list = NULL;

    push(&list, 3);
    push(&list, 8);
    push(&list, 12);
    push(&list, 7);
    push(&list, 2);

    printList(list);

    return 0;
}