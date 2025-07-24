//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>

// Function to swap two elements of an array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort
void bucketSort(float arr[], int n)
{
    // Create n buckets
    int i, j;
    int buckets[n];
    for (i = 0; i < n; ++i) {
        buckets[i] = 0;
    }

    // Fill the buckets with array elements
    for (i = 0; i < n; ++i) {
        ++buckets[(int)(arr[i] * n)];
    }

    // Sort the elements of each bucket
    for (i = 0; i < n; ++i) {
        for (j = 0; j < buckets[i]; ++j) {
            int k;
            for (k = j + 1; k < buckets[i]; ++k) {  
                if (arr[(int)(i * n + j)] > arr[(int)(i * n + k)]) {
                    swap(&arr[(int)(i * n + j)], &arr[(int)(i * n + k)]);
                }
            }
        }
    }
}

// Function to print array elements
void printArray(float arr[], int size)
{
    int i;
    for (i = 0; i < size; ++i) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    float arr[] = {0.88, 0.11, 0.12, 0.23, 0.87, 0.10, 0.34, 0.53, 0.65, 0.21};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Array after sorting:\n");
    printArray(arr, n);

    return 0;
}