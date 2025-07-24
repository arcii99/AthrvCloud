//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int arr[], int n)
{
    // Initialize buckets
    int i, j;
    int buckets[n];
    for (i = 0; i < n; i++)
        buckets[i] = 0;

    // Fill buckets
    for (i = 0; i < n; i++)
        ++buckets[arr[i]];

    // Sort using buckets
    for (i = 0, j = 0; i < n; i++)
        for (; buckets[i] > 0; buckets[i]--)
            arr[j++] = i;
}

int main()
{
    int i, n, arr[100];

    // Get input from user
    printf("Enter the no. of elements to be sorted: ");
    scanf("%d", &n);

    // Generate random array
    srand(time(NULL));
    for (i = 0; i < n; i++)
        arr[i] = rand() % n;

    // Sort array
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}