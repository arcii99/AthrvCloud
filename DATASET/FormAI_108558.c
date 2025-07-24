//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n)
{
    // Create an array of empty buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    // Assign values to the buckets
    for (i = 0; i < n; i++)
    {
        int bucket = n * arr[i];
        count[bucket]++;
    }

    // Sort the elements of each bucket using insertion sort
    for (i = 0; i < n; i++)
    {
        int bucket = count[i];
        for (j = 0; j < bucket; j++)
        {
            int k = j;
            float temp = arr[k];
            while (k > 0 && arr[k - 1] > temp)
            {
                arr[k] = arr[k - 1];
                k--;
            }
            arr[k] = temp;
        }
    }
}

int main()
{
    float arr[] = {0.6, 0.7, 0.5, 0.4, 0.3, 0.2, 0.1};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array is ");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }

    return 0;
}