//FormAI DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

int main()
{
    int i, j, temp;
    int array[ARRAY_SIZE];
    clock_t start, end;
    double time_used;

    // Fill the array with random numbers
    for (i = 0; i < ARRAY_SIZE; i++)
        array[i] = rand() % 10000;

    // Start the benchmark
    start = clock();

    // Sort the array using insertion sort
    for (i = 1; i < ARRAY_SIZE; i++) {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }

    // End the benchmark
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array and the time used
    printf("Sorted Array:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");
    printf("Time used: %f seconds\n", time_used);

    return 0;
}