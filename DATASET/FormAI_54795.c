//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to hold the linked list nodes */
struct Node {
    int data;
    struct Node* next;
};

void Insert(struct Node** head_ref, int new_data)
{
    /* Create a new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    /* Assign the data to the new node and make its next value NULL */
    new_node->data = new_data;
    new_node->next = NULL;
    
    /* If the head is NULL, set the new node as the head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    /* Traverse the linked list to find the last node */
    struct Node* last_node = *head_ref;
    while (last_node->next != NULL)
        last_node = last_node->next;
    
    /* Set the new node as the last node's next node */
    last_node->next = new_node;
}

void Bucket_Sort(int arr[], int n)
{
    /* Determine the maximum value in the array */
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    
    /* Create an array of buckets, each with a linked list */
    struct Node* buckets[max_val + 1];
    for (int i = 0; i < max_val + 1; i++)
        buckets[i] = NULL;
    
    /* Insert each element of the array into the appropriate bucket */
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i];
        Insert(&buckets[bucket_index], arr[i]);
    }
    
    /* Traverse each bucket and concatenate the linked lists */
    int index = 0;
    for (int i = 0; i < max_val + 1; i++) {
        struct Node* current_node = buckets[i];
        while (current_node != NULL) {
            arr[index++] = current_node->data;
            current_node = current_node->next;
        }
    }
}

int main()
{
    int arr[] = {34, 56, 12, 45, 67, 23, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    Bucket_Sort(arr, n);
    
    printf("Array after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}