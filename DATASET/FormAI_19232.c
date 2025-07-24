//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define BUCKET_SIZE 10

void bucket_sort(int *arr, int n)
{
    // Array of buckets
    int buckets[BUCKET_SIZE][ARRAY_SIZE] = {0};
    
    // Fill buckets with elements from array
    for (int i = 0; i < n; i++)
    {
        int bucket_index = (int)(arr[i] / 10);
        int j = 0;
        while (buckets[bucket_index][j] != 0)
            j++;
        buckets[bucket_index][j] = arr[i];
    }
    
    // Sort each bucket and merge into original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        int *bucket = buckets[i];
        int bucket_size = 0;
        while (bucket[bucket_size] != 0)
            bucket_size++;
        if (bucket_size == 0)
            continue;
        // Insertion Sort
        for (int j = 1; j < bucket_size; j++)
        {
            int key = bucket[j];
            int k = j - 1;
            while (k >= 0 && bucket[k] > key)
            {
                bucket[k + 1] = bucket[k];
                k--;
            }
            bucket[k + 1] = key;
        }
        // Merge bucket into original array
        for (int j = 0; j < bucket_size; j++)
        {
            arr[index] = bucket[j];
            index++;
        }
    }
}

int main()
{
    int arr[] = {29, 25, 3, 49, 1, 9, 37, 21, 43, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    bucket_sort(arr, n);
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}