//FormAI DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    // Initialize array with random values between 0-999
    int array[ARRAY_SIZE];
    for(i=0; i<ARRAY_SIZE; i++)
    {
        array[i] = rand() % 1000;
    }

    // Bubble sort algorithm
    start = clock();
    for(i=0; i<ARRAY_SIZE-1; i++)
    {
        for(j=0; j<ARRAY_SIZE-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();

    // Calculate time taken by Bubble sort algorithm
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bubble sort result:\n");
    for(i=0; i<ARRAY_SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nTime taken by Bubble sort algorithm: %f seconds\n\n", cpu_time_used);


    // Selection sort algorithm
    start = clock();
    for(i=0; i<ARRAY_SIZE-1; i++)
    {
        int min_index = i;
        for(j=i+1; j<ARRAY_SIZE; j++)
        {
            if(array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
    end = clock();

    // Calculate time taken by Selection sort algorithm
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Selection sort result:\n");
    for(i=0; i<ARRAY_SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nTime taken by Selection sort algorithm: %f seconds\n\n", cpu_time_used);

    return 0;
}