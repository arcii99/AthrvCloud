//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main()
{
    int i, j, temp;
    int arr[SIZE];
    clock_t start, end;

    // Generate random numbers for array
    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % 10000;

    // Benchmarking Bubble Sort Algorithm
    start = clock();
    for (i = 0; i < SIZE - 1; i++)
        for (j = 0; j < SIZE - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    end = clock();

    printf("Bubble Sort Algorithm Time Complexity for array size %d: %f sec\n", SIZE, (double)(end - start) / CLOCKS_PER_SEC);

    // Generate random numbers for array
    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % 10000;

    // Benchmarking Quick Sort Algorithm
    start = clock();
    quickSort(arr, 0, SIZE - 1);
    end = clock();

    printf("Quick Sort Algorithm Time Complexity for array size %d: %f sec\n", SIZE, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

// Implementation of Quick Sort Algorithm
void quickSort(int arr[], int low, int high)
{
    int i, j, pivot, temp;

    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;

        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i <= high)
                i++;

            while (arr[j] > arr[pivot] && j >= low)
                j--;

            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}