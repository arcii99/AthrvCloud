//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int arr[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Populate array with random numbers
    for(int i=0; i<ARRAY_SIZE; i++)
        arr[i] = rand() % 1000;

    // Bubble sort algorithm
    start = clock();
    for(int i=0; i<ARRAY_SIZE-1; i++)
    {
        for(int j=0; j<ARRAY_SIZE-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();

    // Calculate CPU time used by bubble sort
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort time: %f seconds\n", cpu_time_used);

    // Selection sort algorithm
    start = clock();
    for(int i=0; i<ARRAY_SIZE-1; i++)
    {
        int min_idx = i;
        for(int j=i+1; j<ARRAY_SIZE; j++)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    end = clock();

    // Calculate CPU time used by selection sort
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort time: %f seconds\n", cpu_time_used);

    return 0;
}