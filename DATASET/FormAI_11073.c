//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n)
{
    int i, j;
    float count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        (count[(int)arr[i]])++;

    for (i = 0, j = 0; i < n; i++)
        for(; count[i] > 0; (count[i])--)
            arr[j++] = i;
}

void printArray(float arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

int main()
{
    float arr[] = {0.1, 0.6, 0.5, 0.2, 0.9, 0.2, 0.5, 1.0, 0.3, 0.4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted Array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);
    return 0;
}