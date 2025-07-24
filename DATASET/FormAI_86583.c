//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// This program implements the bucket sort algorithm using linked lists to store the elements within the buckets.

// Define a bucket structure to store the elements within each bucket
struct bucket
{
    float value;
    struct bucket *next;
};

// A function to insert an element into a bucket in sorted order
void insert(struct bucket **bucket_ptr, float value)
{
    struct bucket *current = *bucket_ptr;
    struct bucket *new_node = (struct bucket*) malloc(sizeof(struct bucket));
    new_node->value = value;
    new_node->next = NULL;
    
    if (current == NULL)
    {
        // If the bucket is empty, set the new node as the head
        *bucket_ptr = new_node;
    }
    else if (current->value > value)
    {
        // If the new node should be the new head, set it as the head and link its next pointer to the old head
        new_node->next = current;
        *bucket_ptr = new_node;
    }
    else
    {
        // Traverse the list until we reach the correct position to insert the new node
        while (current->next != NULL && current->next->value < value)
        {
            current = current->next;
        }
        // Insert the new node into the list
        new_node->next = current->next;
        current->next = new_node;
    }
}

void bucket_sort(float *arr, int size)
{
    // Create an array of linked lists to represent the buckets
    struct bucket *buckets[10] = {NULL};
    int i;
    
    // Iterate through the array and insert each element into the appropriate bucket based on its value
    for (i = 0; i < size; i++)
    {
        int bucket_index = (int) (arr[i] * 10);
        insert(&buckets[bucket_index], arr[i]);
    }
    
    // Iterate through the buckets and concatenate them back into the original array in order
    int j = 0;
    for (i = 0; i < 10; i++)
    {
        struct bucket *current = buckets[i];
        while (current != NULL)
        {
            arr[j] = current->value;
            current = current->next;
            j++;
        }
    }
}

int main()
{
    float arr[] = {0.73, 0.53, 0.39, 0.76, 0.34, 0.44, 0.21, 0.19, 0.32, 0.41, 0.53};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    printf("Unsorted Array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
    
    bucket_sort(arr, size);
    
    printf("Sorted Array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
    
    return 0;
}