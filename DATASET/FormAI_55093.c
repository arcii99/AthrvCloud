//FormAI DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size)
{
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {9, 4, 8, 3, 1, 6, 5, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArr(arr, size);

    selectionSort(arr, size);

    printf("Sorted array: ");
    printArr(arr, size);

    return 0;
}