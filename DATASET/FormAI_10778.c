//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bucketSort(int arr[], int size)
{
    // Create an array of empty buckets
    int* bucket[BUCKET_SIZE];
    for(int i = 0; i < BUCKET_SIZE; i++)
    {
        bucket[i] = NULL;
    }

    // Calculate maximum and minimum elements in the array
    int max = arr[0], min = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    // Calculate range of each bucket
    float range = (float)(max - min + 1) / BUCKET_SIZE;

    // Distribute data to the buckets
    for(int i = 0; i < size; i++)
    {
        int index = (int)((arr[i] - min) / range);
        if(bucket[index] == NULL)
        {
            bucket[index] = (int*)malloc(sizeof(int));
            *bucket[index] = arr[i];
        }
        else
        {
            int* current = bucket[index];
            while(*current != -1)
            {
                current++;
            }
            current = (int*)realloc(bucket[index], (current - bucket[index] + 2) * sizeof(int));
            *(current + 1) = -1;
            *current = arr[i];
        }
    }

    // Sort each bucket
    for(int i = 0; i < BUCKET_SIZE; i++)
    {
        if(bucket[i] != NULL)
        {
            int* current = bucket[i];
            while(*current != -1)
            {
                for(int j = 0; j < current - bucket[i]; j++)
                {
                    if(*(current - j) > *current)
                    {
                        int temp = *(current - j);
                        *(current - j) = *current;
                        *current = temp;
                    }
                }
                current++;
            }
        }
    }

    // Copy the buckets into the original array in order
    int* current = arr;
    for(int i = 0; i < BUCKET_SIZE; i++)
    {
        if(bucket[i] != NULL)
        {
            int* bucketPtr = bucket[i];
            while(*bucketPtr != -1)
            {
                *current = *bucketPtr;
                current++;
                bucketPtr++;
            }
            free(bucket[i]);
        }
    }
}

int main()
{
    int arr[] = {82, 78, 36, 11, 91, 2, 33, 22, 49, 75};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("After sorting: ");
    printArray(arr, size);

    return 0;
}