//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* n)
{
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

int main()
{
    struct node* head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);

    printf("Scheduled Appointments: ");
    printList(head);

    return 0;
}