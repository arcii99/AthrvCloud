//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

/* Define constants */
#define ARRAY_SIZE 10
#define BUCKET_SIZE 5

/* Define functions */
void printArray(int arr[], int size);
void bucketSort(int arr[], int size);

int main()
{
    /* Initialize array */
    int arr[ARRAY_SIZE] = {4, 2, 9, 5, 1, 8, 3, 6, 7, 0};

    printf("Before sorting:\n");
    printArray(arr, ARRAY_SIZE);

    bucketSort(arr, ARRAY_SIZE);

    printf("After sorting:\n");
    printArray(arr, ARRAY_SIZE);

    return 0;
}

/* Function to print array */
void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to perform bucket sort */
void bucketSort(int arr[], int size)
{
    /* Define variables */
    int i, j, k, bucketCount;
    int minValue = arr[0];
    int maxValue = arr[0];
    int bucket[BUCKET_SIZE][ARRAY_SIZE];

    /* Find minimum and maximum values */
    for(i = 1; i < size; i++)
    {
        if(arr[i] < minValue)
            minValue = arr[i];
        else if(arr[i] > maxValue)
            maxValue = arr[i];
    }

    /* Calculate bucket size */
    float range = (float)(maxValue - minValue + 1) / BUCKET_SIZE;

    /* Initialize buckets */
    for(i = 0; i < BUCKET_SIZE; i++)
    {
        bucketCount = 0;
        for(j = 0; j < size; j++)
        {
            if(arr[j] >= i * range + minValue && arr[j] < (i + 1) * range + minValue)
            {
                bucket[i][bucketCount++] = arr[j];
            }
        }
    }

    /* Sort buckets */
    for(i = 0; i < BUCKET_SIZE; i++)
    {
        for(j = 0; j < bucketCount; j++)
        {
            for(k = 0; k < bucketCount - j - 1; k++)
            {
                if(bucket[i][k] > bucket[i][k + 1])
                {
                    int temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    /* Merge buckets */
    int index = 0;
    for(i = 0; i < BUCKET_SIZE; i++)
    {
        for(j = 0; j < bucketCount; j++)
        {
            if(bucket[i][j] != 0)
                arr[index++] = bucket[i][j];
        }
    }
}