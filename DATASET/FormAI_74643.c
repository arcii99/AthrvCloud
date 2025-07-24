//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main()
{
    int arr[MAX_SIZE], temp, n, i, j;
    clock_t t;
    double time_taken;

    /* Generate random array */
    srand(time(0));
    n = rand() % MAX_SIZE + 1;
    for (i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    /* Bubble Sort */
    t = clock();
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("Bubble Sort Time Taken: %f seconds\n", time_taken);

    /* Quick Sort */
    t = clock();
    quick_sort(arr, 0, n - 1);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("Quick Sort Time Taken: %f seconds\n", time_taken);

    return 0;
}

/* Quick Sort Implementation */
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1), j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}