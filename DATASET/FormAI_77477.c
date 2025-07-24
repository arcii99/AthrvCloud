//FormAI DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert_front(struct node** head, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void insert_end(struct node** head, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void delete_node(struct node** head, int key) {
    struct node* temp = *head, * prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void print_list(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;
    insert_front(&head, 7);
    insert_front(&head, 3);
    insert_end(&head, 1);
    insert_front(&head, 4);
    insert_end(&head, 5);
    printf("Linked List: ");
    print_list(head);
    printf("\nDeleting node with data value 3...\n");
    delete_node(&head, 3);
    printf("Linked List after deletion: ");
    print_list(head);
    return 0;
}