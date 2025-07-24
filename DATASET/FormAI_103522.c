//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Function to sort using bucket sort
void bucketSort(int array[], int n)
{
    // Create buckets
    int i, j;
    int count[MAX] = { 0 };
    for (i = 0; i < n; i++)
        count[array[i]]++;

    // Traverse through all buckets and sort
    for (i = 0, j = 0; i < MAX; i++)
        for (; count[i] > 0; count[i]--)
            array[j++] = i;
}

// Driver code
int main()
{
    int array[] = { 3, 6, 9, 4, 5, 7, 2, 1, 8, 0 };
    int n = sizeof(array) / sizeof(array[0]);
    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    bucketSort(array, n);

    printf("Array sorted successfully using Bucket Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}