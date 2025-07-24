//FormAI DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void add_at_beg(struct node** head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void add_at_end(struct node** head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void delete_node(struct node** head, int data)
{
    struct node* temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void print_list(struct node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node* head = NULL;
    add_at_beg(&head, 5);
    add_at_beg(&head, 4);
    add_at_end(&head, 6);
    add_at_end(&head, 7); 
    printf("Original List:");
    print_list(head);
    delete_node(&head, 6);
    printf("After deletion of 6:");
    print_list(head);
    return 0;
}