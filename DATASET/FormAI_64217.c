//FormAI DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node for the linked list
struct node {
    int data;
    struct node *next;
};

// Functions to handle the linked list operations
void insert_at_beginning(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_after(struct node *prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The previous node cannot be NULL.\n");
        return;
    }
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insert_at_end(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void delete_node(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found in the linked list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void print_list(struct node *head_ref) {
    printf("The linked list is as follows:\n");
    while (head_ref != NULL) {
        printf("%d ", head_ref->data);
        head_ref = head_ref->next;
    }
    printf("\n");
}

// Driver function to test the linked list operations
int main() {
    struct node* head = NULL;

    insert_at_end(&head, 6);
    insert_at_beginning(&head, 7);
    insert_at_end(&head, 8);
    insert_after(head->next, 10);

    printf("Insertions made into the linked list:\n");
    print_list(head);

    delete_node(&head, 7);
    delete_node(&head, 10);

    printf("Deletions made from the linked list:\n");
    print_list(head);

    return 0;
}