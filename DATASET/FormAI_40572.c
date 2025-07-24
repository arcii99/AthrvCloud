//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size);

void mergeSort(int *arr, int size)
{
    if(size < 2)
    {
        return;
    }

    int mid = size / 2;
    int left[mid], right[size - mid];

    for(int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for(int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    int i = 0, j = 0, k = 0;

    while(i < mid && j < size - mid)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < mid)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < size - mid)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    printf("Array after sorting: ");
    printArray(arr, size);
}

void printArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {8, 2, 7, 1, 4, 9, 3, 6, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArray(arr, size);

    mergeSort(arr, size);

    return 0;
}