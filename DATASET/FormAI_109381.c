//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 10

void printArray(int A[], int n) // helper function to print array
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
}

void bucketSort(int A[], int n)
{
    int max_val = A[0];

    for (int i = 0; i < n; i++)
    {
        if (A[i] > max_val)
            max_val = A[i];
    }

    int bucket_size = max_val / 5 + 1; // set bucket size

    int **buckets = malloc(bucket_size * sizeof(int *)); // allocate memory for buckets

    for (int i = 0; i < bucket_size; i++)
    {
        buckets[i] = malloc(n * sizeof(int));
    }

    int count[bucket_size]; // use count array to count number of integers in each bucket

    for (int i = 0; i < bucket_size; i++)
    {
        count[i] = 0;
    }

    // add elements into buckets
    for (int i = 0; i < n; i++)
    {
        int bucket_idx = A[i] / 5;

        buckets[bucket_idx][count[bucket_idx]] = A[i];
        count[bucket_idx] += 1;
    }

    // sort elements in each bucket
    for (int i = 0; i < bucket_size; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            for (int k = j + 1; k < count[i]; k++)
            {
                if (buckets[i][j] > buckets[i][k])
                {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }

    int idx = 0;

    for (int i = 0; i < bucket_size; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            A[idx++] = buckets[i][j];
        }
    }

    // free memory
    for (int i = 0; i < bucket_size; i++)
    {
        free(buckets[i]);
    }

    free(buckets);
}

int main()
{
    int A[ARRAY_SIZE] = {6, 3, 8, 4, 2, 9, 1, 5, 7, 0};

    printf("Before sorting: ");
    printArray(A, ARRAY_SIZE);

    bucketSort(A, ARRAY_SIZE);

    printf("\nAfter sorting: ");
    printArray(A, ARRAY_SIZE);

    return 0;
}