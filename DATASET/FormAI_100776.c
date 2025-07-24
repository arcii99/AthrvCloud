//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to swap two integers
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers using Bucket Sort algorithm
void bucketSort(int arr[], int n)
{
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Divide the elements of the array into buckets
    int bucketSize = max / n;
    int bucketCount = n;
    int* buckets[bucketCount];
    for (int i = 0; i < bucketCount; i++)
    {
        buckets[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / bucketSize;
        if (buckets[bucketIndex] == NULL)
        {
            buckets[bucketIndex] = (int*) malloc(bucketSize * sizeof(int));
            for (int j = 0; j < bucketSize; j++)
            {
                buckets[bucketIndex][j] = -1;
            }
        }
        int j = 0;
        while (buckets[bucketIndex][j] != -1)
        {
            j++;
        }
        buckets[bucketIndex][j] = arr[i];
    }

    // Sort the elements of each bucket using Bubble Sort algorithm
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; buckets[i] != NULL && j < bucketSize; j++)
        {
            for (int k = j + 1; buckets[i][k] != -1 && k < bucketSize; k++)
            {
                if (buckets[i][j] > buckets[i][k])
                {
                    swap(&buckets[i][j], &buckets[i][k]);
                }
            }
        }
    }

    // Concatenate the sorted elements of all the buckets into the original array
    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        if (buckets[i] != NULL)
        {
            for (int j = 0; buckets[i][j] != -1 && j < bucketSize; j++)
            {
                arr[index++] = buckets[i][j];
            }
            free(buckets[i]);
        }
    }
}

// Function to print an array of integers
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Test the Bucket Sort algorithm
    int arr[] = {12, 8, 15, 7, 21, 13, 16, 4, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}