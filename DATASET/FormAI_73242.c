//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int NUM_ITERATIONS = 1000000;
    clock_t start_t, end_t;
    double total_t;

    int arr[NUM_ITERATIONS];
    int i, j, temp;

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < NUM_ITERATIONS; i++)
        arr[i] = rand();

    // Bubble sort benchmarking
    start_t = clock();
    for (i = 0; i < NUM_ITERATIONS-1; i++)
    {
        for (j = 0; j < NUM_ITERATIONS-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Bubble sort took %.3f seconds\n", total_t);

    // Quick sort benchmarking
    srand(time(NULL));
    for (i = 0; i < NUM_ITERATIONS; i++)
        arr[i] = rand();

    start_t = clock();
    quicksort(arr, 0, NUM_ITERATIONS-1);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Quick sort took %.3f seconds\n", total_t);

    return 0;
}

void quicksort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}