//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert(node **head, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL) //if linked list is empty
        *head = newNode;

    else //if linked list is not empty
    {
        node *temp = *head;
 
        while(temp->next != NULL)
            temp = temp->next;
 
        temp->next = newNode;
    }
}

void printBucket(node *head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void bucketSort(int arr[], int n)
{
    node *bucket[n];

    for(int i = 0; i < n; i++)
        bucket[i] = NULL;

    for(int i = 0; i < n; i++)
    {
        node* ptr = (node *)malloc(sizeof(node));
        ptr->data = arr[i];
        ptr->next = NULL;
        int bucketIndex = (n * arr[i])/100;
        insert(&bucket[bucketIndex], arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("Bucket no. %d: ", i);
        printBucket(bucket[i]);
        printf("\n");
    }
}

int main()
{
    int arr[10] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nAfter sorting: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}