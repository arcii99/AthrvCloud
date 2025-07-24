//FormAI DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

void insert_node(node** head, int val) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void print_list(node* head) {
    printf("List: ");
    for (node* current = head; current != NULL; current = current->next) {
        printf("%d ", current->val);
    }
    printf("\n");
}

void delete_list(node** head) {
    node* current = *head;
    node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    print_list(head);
    delete_list(&head);
    print_list(head);
    return 0;
}