//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Helper function to swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main bucket sort function
void bucketSort(int arr[], int n, int bucket_count)
{
    // Step 1: Initialize buckets
    int i, j, k;
    int **buckets = (int **)malloc(bucket_count * sizeof(int *));
    for (i = 0; i < bucket_count; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
            buckets[i][j] = -1;
    }

    // Step 2: Populate the buckets
    for (i = 0; i < n; i++)
    {
        int bi = arr[i] / bucket_count;
        for (j = 0; j < n; j++)
        {
            if (buckets[bi][j] == -1)
            {
                buckets[bi][j] = arr[i];
                break;
            }
        }
    }

    // Step 3: Sort each bucket using insertion sort
    for (i = 0; i < bucket_count; i++)
    {
        int bucket_size = 0;
        while (buckets[i][bucket_size] != -1)
            bucket_size++;

        for (j = 1; j < bucket_size; j++)
        {
            int key = buckets[i][j];
            k = j - 1;
            while (k >= 0 && buckets[i][k] > key)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Step 4: Merge the buckets
    int index = 0;
    for (i = 0; i < bucket_count; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (buckets[i][j] != -1)
            {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }
}

// Driver function
int main()
{
    int arr[] = {17, 21, 12, 14, 15, 16, 19, 18, 13, 20, 23, 24, 22, 26, 25};
    int n = sizeof(arr) / sizeof(int);
    int bucket_count = 5;

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Calling bucket sort function
    bucketSort(arr, n, bucket_count);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
  
    return 0;
}