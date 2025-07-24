//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Let's declare some variables
    int array[1000000];
    clock_t start, end;
    double cpu_time_used;
    int i, j, temp;

    // Fill the array with random numbers
    for (i = 0; i < 1000000; i++) {
        array[i] = rand() % 100000;
    }

    // Print a happy message to start the program
    printf("Let's benchmark the sorting of a million numbers!\n");

    // Start the timer and the sorting algorithm
    start = clock();

    for (i = 0; i < 1000000; i++) {
        for (j = i + 1; j < 1000000; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // End the timer and calculate the CPU time used
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array and the time it took to sort it
    printf("The array is now sorted! Yay!\n");
    for (i = 0; i < 1000000; i++) {
        printf("%d ", array[i]);
    }
    printf("\nIt took me %f seconds to sort the array. This is amazing!\n", cpu_time_used);

    return 0;
}