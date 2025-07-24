//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Defining the structure of a node in a linked list
struct Node
{
    int value;
    struct Node* next;
};

int find_max(int* arr, int size)
{
    int max = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void insert(struct Node** head_ref, int value)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void bucket_sort(int* arr, int size)
{
    int max = find_max(arr, size);
    int num_buckets = (max / 10) + 1;

    struct Node** buckets = (struct Node**)malloc(num_buckets * sizeof(struct Node*));

    // Initializing all buckets to NULL
    for(int i = 0; i < num_buckets; i++)
    {
        buckets[i] = NULL;
    }

    // Inserting elements into their respective buckets
    for(int i = 0; i < size; i++)
    {
        int index = arr[i] / 10;
        insert(&buckets[index], arr[i]);
    }

    // Sorting individual buckets using an insertion sort
    for(int i = 0; i < num_buckets; i++)
    {
        struct Node* current = buckets[i];
        while(current != NULL)
        {
            struct Node* temp = current->next;
            struct Node* prev = NULL;
            struct Node* comparator = current;
            while(comparator->next != NULL)
            {
                if(comparator->next->value < current->value)
                    break;
                prev = comparator;
                comparator = comparator->next;
            }
            if(comparator != current)
            {
                current->next = comparator->next;
                comparator->next = current;
                if(prev != NULL)
                    prev->next = comparator;
                else
                    buckets[i] = current;
            }
            current = temp;
        }
    }

    // Copying sorted elements back into original array
    int i = 0;
    for(int j = 0; j < num_buckets; j++)
    {
        struct Node* current = buckets[j];
        while(current != NULL)
        {
            arr[i] = current->value;
            current = current->next;
            i++;
        }
    }
}

int main()
{
    int arr[] = {15, 2, 8, 9, 5, 10, 23, 14, 99, 72, 46};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bucket_sort(arr, size);

    printf("\nArray after sorting:\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}