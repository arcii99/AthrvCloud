//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(float arr[], int n)
{
    // Create n empty buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    // Fill the buckets
    for (i = 0; i < n; i++) {
        int index = n * arr[i];
        count[index]++;
    }

    // Sort the elements of each bucket
    for (i = 0; i < n; i++) {
        int index = n * arr[i];
        float temp[count[index]];
        for (j = 0; j < count[index]; j++)
            temp[j] = arr[j];
        for (j = 0; j < count[index] - 1; j++) {
            int k;
            float smallest = temp[j];
            int index_smallest = j;
            for (k = j + 1; k < count[index]; k++) {
                if (temp[k] < smallest) {
                    smallest = temp[k];
                    index_smallest = k;
                }
            }
            float val = temp[j];
            temp[j] = smallest;
            temp[index_smallest] = val;
        }
        for (j = 0; j < count[index]; j++)
            arr[j] = temp[j];
    }
}

// Function to print an array
void printArray(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);
}

// Driver code
int main()
{
    float arr[] = { 0.18, 0.16, 0.15, 0.39, 0.37, 0.59 };
    int n = sizeof(arr) / sizeof(float);
    bucketSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}