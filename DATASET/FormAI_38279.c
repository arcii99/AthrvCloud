//FormAI DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void addNode(Node** headRef, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = *headRef;
    *headRef = temp;
}

void deleteNode(Node** headRef, int data)
{
    Node* temp = *headRef;
    Node* prev = NULL;

    if (temp != NULL && temp->data == data)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    Node* head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    printf("Initial linked list: ");
    printList(head);

    deleteNode(&head, 2);

    printf("\nLinked list after deleting 2: ");
    printList(head);

    return 0;
}