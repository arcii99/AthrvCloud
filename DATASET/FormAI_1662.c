//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>  
#include <stdlib.h> 

struct node  
{  
    int data;  
    struct node* next;  
};  
  
typedef struct node* Node;  
  
Node getnode()  
{  
    Node p;  
    p = (Node)malloc(sizeof(struct node));  
    if (p == NULL)  
    {  
        printf("Memory could not be allocated");  
        exit(0);  
    }  
    return p;  
}  
  
void insert(Node* head, int x)  
{  
    Node p, q;  
    p = getnode();  
    p->data = x;  
    p->next = NULL;  
    if (*head == NULL)  
        *head = p;  
    else  
    {  
        q = *head;  
        while (q->next != NULL)  
            q = q->next;  
        q->next = p;  
    }  
}  

void bucketSort(int arr[], int n, int k)  
{  
    int i, j;  
    Node *bucket;  
    bucket = (Node*)malloc(k * sizeof(struct node));  
    
    for (i = 0; i < k; i++)  
        bucket[i] = NULL;  
        
    for (i = 0; i < n; i++)  
    {  
        Node p;  
        int index = k * arr[i] / (10.0 + 1);  
        insert(&bucket[index], arr[i]);  
    }  
  
    for (i = 0; i < k; i++)  
    {  
        printf("Bucket [%d] :", i);  
        for (Node p = bucket[i]; p != NULL; p = p->next)  
            printf("%d ", p->data);  
        printf("\n");  
    }  
    
    for (i = 0; i < k; i++)  
    {  
        int count = 0;  
        for (Node p = bucket[i]; p != NULL; p = p->next)  
            arr[count++] = p->data;  
    }  
}  
  
void display(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  
  
int main()  
{  
    int arr[20] = {18, 5, 13, 19, 15, 14, 7, 11, 8, 12, 20, 4, 10, 3, 6, 1, 9, 2, 16, 17};  
    
    int n = sizeof(arr) / sizeof(arr[0]);  
    int k = 10;
    
    printf("Before sorting: ");  
    display(arr, n);  
    
    bucketSort(arr, n, k);  
    
    printf("\nAfter sorting: ");  
    display(arr, n);  
    return 0;  
}