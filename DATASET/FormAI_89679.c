//FormAI DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

//node structure
struct node {
    int data;
    struct node* next;
};

//function to add a node at the end of the linked list
void append(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

//function to print the linked list
void display(struct node* head) {
    printf("The linked list is: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    display(head);

    return 0;
}