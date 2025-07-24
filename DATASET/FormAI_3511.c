//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <time.h>

int main()
{
    int n = 1000000;
    int arr[n];
    int i, j, temp;

    // Generate random numbers and store in array
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }

    // Bubble sort
    clock_t start = clock();
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t end = clock();
    double time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds to execute.\n", time_elapsed);

    // Selection sort
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
    start = clock();
    for (i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    end = clock();
    time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort took %f seconds to execute.\n", time_elapsed);

    return 0;
}