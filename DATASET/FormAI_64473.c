//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void allocateNode(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void deallocateNode(struct Node* head) {
    struct Node* temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
}

int main() {
    struct Node* head = NULL;

    allocateNode(&head, 10);
    allocateNode(&head, 20);
    allocateNode(&head, 30);
    allocateNode(&head, 40);

    printf("List contents before deallocation:\n");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    deallocateNode(head);

    printf("\nList deallocated successfully!");

    return 0;
}