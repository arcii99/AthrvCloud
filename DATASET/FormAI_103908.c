//FormAI DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void searchIndex(struct Node *head, int index)
{
    int i=0;
    struct Node *current = head;
    while(current != NULL)
    {
        if(i==index)
        {
            printf("Index %d contains data %d\n", index, current->data);
            return;
        }
        else
        {
            current = current->next;
            i++;
        }
    }
    printf("Error: Index out of bounds\n");
}

int main()
{
    struct Node *head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 20);
    
    searchIndex(head, 2);
    searchIndex(head, 4);
    
    return 0;
}