//FormAI DATASET v1.0 Category: Benchmarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main()
{
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    int array[SIZE]; // declare an array of SIZE elements

    // populate the array with random integers between 0-999
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    printf("Before sorting:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nSorting...\n");

    start = clock(); // mark the starting time

    // insertion sort algorithm
    for (i = 1; i < SIZE; i++) {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;
    }

    end = clock(); // mark the ending time

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate the CPU time used

    printf("\nAfter sorting:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nCPU time used: %f seconds.\n", cpu_time_used);

    return 0;
}