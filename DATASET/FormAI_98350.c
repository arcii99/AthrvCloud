//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node;

void push(node **head, int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

int pop(node **head) {
    int value = (*head)->data;
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return value;
}

void print_list(node *head) {
    printf("Stack: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    print_list(head);
    printf("Popped value: %d\n", pop(&head));
    printf("Popped value: %d\n", pop(&head));
    print_list(head);
    return 0;
}