//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[SIZE], i, j;

    srand(time(0));
    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000000;

    printf("Unsorted array: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    clock_t t1, t2;

    t1 = clock();
    selection_sort(arr, SIZE);
    t2 = clock();
    printf("\nTime taken by Selection Sort: %f seconds", (double)(t2 - t1) / CLOCKS_PER_SEC);

    t1 = clock();
    insertion_sort(arr, SIZE);
    t2 = clock();
    printf("\nTime taken by Insertion Sort: %f seconds", (double)(t2 - t1) / CLOCKS_PER_SEC);

    printf("\nSorted array: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}