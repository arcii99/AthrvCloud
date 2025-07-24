//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **head, int val) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = (*head);
    (*head) = new_node;
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    display(head);
    return 0;
}