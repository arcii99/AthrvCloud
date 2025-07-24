//FormAI DATASET v1.0 Category: Sorting ; Style: mathematical
// Sorting program in mathematical style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater
           than key, to one position ahead of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int main()
{
    int arr[ARRAY_SIZE], i;
    srand(time(NULL)); // Seed the random number generator

    // Generate random numbers and fill the array with them
    for (i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 100;

    printf("Original array:\n");
    print_array(arr, ARRAY_SIZE);

    // Perform bubble sort and print the sorted array
    bubble_sort(arr, ARRAY_SIZE);
    printf("Array after bubble sort:\n");
    print_array(arr, ARRAY_SIZE);

    // Reset the array to random numbers again
    for (i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 100;

    printf("Original array:\n");
    print_array(arr, ARRAY_SIZE);

    // Perform selection sort and print the sorted array
    selection_sort(arr, ARRAY_SIZE);
    printf("Array after selection sort:\n");
    print_array(arr, ARRAY_SIZE);

    // Reset the array to random numbers again
    for (i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 100;

    printf("Original array:\n");
    print_array(arr, ARRAY_SIZE);

    // Perform insertion sort and print the sorted array
    insertion_sort(arr, ARRAY_SIZE);
    printf("Array after insertion sort:\n");
    print_array(arr, ARRAY_SIZE);

    return 0;
}