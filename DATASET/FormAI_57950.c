//FormAI DATASET v1.0 Category: Benchmarking ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int i, j, temp;
    int arr[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Filling the array with random numbers
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 1000;

    // Bubble sort benchmarking
    start = clock();
    for(i = 0; i < ARRAY_SIZE-1; i++)
        for(j = 0; j < ARRAY_SIZE-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds to execute. \n", cpu_time_used);

    // Selection sort benchmarking
    start = clock();
    for(i = 0; i < ARRAY_SIZE-1; i++)
    {
        int min_index = i;
        for(j = i+1; j < ARRAY_SIZE; j++)
            if(arr[j] < arr[min_index])
                min_index = j;
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds to execute. \n", cpu_time_used);

    // Insertion sort benchmarking
    start = clock();
    for(i = 1; i < ARRAY_SIZE; i++)
    {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds to execute. \n", cpu_time_used);

    return 0;
}