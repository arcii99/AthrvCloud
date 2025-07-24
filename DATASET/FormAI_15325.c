//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>

struct Node {
    int value;
    struct Node* next;
};

void addNode(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = *head;

    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL");
}

int main() {
    struct Node* head = NULL;
    addNode(&head, 3);
    addNode(&head, 7);
    addNode(&head, 8);
    addNode(&head, 13);

    printList(head);

    return 0;
}