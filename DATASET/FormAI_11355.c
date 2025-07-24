//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("Original array: ");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);

    insertionSort(arr, n);

    printf("\nSorted array: ");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}