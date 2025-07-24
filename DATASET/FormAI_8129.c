//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* function declaration */
void printArray(int* arr, int size);
void bubbleSort(int* arr, int size);

int main()
{
    int arr[10] = {2, 5, 1, 6, 9, 8, 3, 4, 7, 0};

    // print unsorted array
    printf("Unsorted Array: ");
    printArray(arr, 10);

    // sort the array using Bubble Sort
    bubbleSort(arr, 10);

    // print sorted array
    printf("Sorted Array: ");
    printArray(arr, 10);

    return 0;
}

/* function definition for printing an array */
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* function definition for Bubble Sort algorithm */
void bubbleSort(int* arr, int size)
{
    int i, j, temp;

    for (i = 0; i < size-1; i++)
    {
        // position i will be the last sorted element
        // so we can skip it and start at j=i+1
        for (j = i+1; j < size; j++)
        {
            // compare adjacent elements and swap them if necessary
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}