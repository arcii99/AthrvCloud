//FormAI DATASET v1.0 Category: Benchmarking ; Style: Alan Touring
// Hello, I am a benchmarking program in C
// I will test the speed of memory allocation and deallocation using different methods
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

int main()
{
    double malloc_time = 0.0, calloc_time = 0.0, free_time = 0.0;
    clock_t start, end;

    // Benchmarking memory allocation using malloc
    int *arr1 = NULL;
    start = clock();
    arr1 = (int *) malloc(ARRAY_SIZE * sizeof(int));
    end = clock();
    malloc_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Benchmarking memory allocation using calloc
    int *arr2 = NULL;
    start = clock();
    arr2 = (int *) calloc(ARRAY_SIZE, sizeof(int));
    end = clock();
    calloc_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Benchmarking memory deallocation using free
    start = clock();
    free(arr1);
    end = clock();
    free_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Memory allocation using malloc took %.6f seconds\n", malloc_time);
    printf("Memory allocation using calloc took %.6f seconds\n", calloc_time);
    printf("Memory deallocation using free took %.6f seconds\n", free_time);

    return 0;
}