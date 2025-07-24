//FormAI DATASET v1.0 Category: Benchmarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // define the size of an array

// Function to swap elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform bubble sort
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// Function to perform quick sort
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        quick_sort(arr, low, i);
        quick_sort(arr, i + 2, high);
    }
}

int main()
{
    srand(time(NULL)); // seed for random values
    int arr[ARRAY_SIZE]; // declare an array
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % ARRAY_SIZE; // fill array with random values

    clock_t start, end; // variables to measure time

    // bubble sort benchmark
    printf("Bubble Sort Benchmark\n");
    start = clock(); // get start time
    bubble_sort(arr, ARRAY_SIZE); // sort array using bubble sort
    end = clock(); // get end time
    printf("Time Taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // quick sort benchmark
    printf("\nQuick Sort Benchmark\n");
    start = clock(); // get start time
    quick_sort(arr, 0, ARRAY_SIZE - 1); // sort array using quick sort
    end = clock(); // get end time
    printf("Time Taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}