//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n, int range)
{
    int i, j;
    int count[range];
    for (i = 0; i < range; i++)
        count[i] = 0;

    // Count the number of elements in each bucket
    for (i = 0; i < n; i++)
        count[arr[i]]++;

    // Sort each bucket
    for (i = 0, j = 0; i < range; i++)
        for (; count[i] > 0; count[i]--)
            arr[j++] = i;
}

// Driver program
int main()
{
    int arr[] = {29, 1, 41, 50, 91, 2, 17, 53};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range = 100;

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    bucketSort(arr, n, range);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}