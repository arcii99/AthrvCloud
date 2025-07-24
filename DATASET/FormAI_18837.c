//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using Bucket Sort
void bucketSort(float arr[], int n)
{
    // Create n buckets initialized with empty lists
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    // Put array elements in different buckets based on their decimal values
    for (i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        count[bucketIndex]++;
    }

    // Sort each bucket individually using a simple Insertion Sort algorithm
    for (i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        float temp = arr[i];
        int k = count[bucketIndex];

        for (j = i - 1; j >= k; j--)
            arr[j + 1] = arr[j];

        arr[k] = temp;
        count[bucketIndex]--;
    }
}

int main()
{
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}