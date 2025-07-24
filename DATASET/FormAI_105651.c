//FormAI DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(void)
{
    int i;
    double time_taken;
    clock_t t_start, t_end;

    int *array = malloc(sizeof(int) * ARRAY_SIZE);

    // Initialize the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Start the benchmarking timer
    t_start = clock();

    // Sort the array using bubble sort
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        int j;
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Stop the benchmarking timer
    t_end = clock();

    // Calculate the time taken
    time_taken = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;

    printf("Sorted %d elements in %f seconds using bubble sort\n", ARRAY_SIZE, time_taken);

    free(array);

    return 0;
}