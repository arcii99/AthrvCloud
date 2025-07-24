//FormAI DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>

/* This is an example program that sorts an array of integers in descending order using selection sort algorithm. */

void selectionSort(int arr[], int size)
{
    int i, j, maxIndex, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the maximum element in unsorted array
        maxIndex = i;
        for (j = i+1; j < size; j++)
        {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        // Swap the found maximum element with the first element
        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[10] = {2,5,1,7,4,8,3,0,9,6};
    int i;

    printf("Original array: ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    selectionSort(arr, 10);

    printf("\nSorted array in descending order: ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    return 0;
}