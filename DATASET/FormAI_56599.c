//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int ARRAY_SIZE = 10000;
    int i, j, temp, array[ARRAY_SIZE];
    clock_t start_time, end_time;
    double total_time;

    srand(time(NULL)); // Seed for random number generation

    // Populate array with random values
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Measure time taken to sort the array using bubble sort algorithm
    start_time = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end_time = clock();
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print sorted array
    printf("Sorted Array using Bubble Sort:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    // Print time taken to sort the array
    printf("\n\nTime taken to sort array using Bubble Sort: %.6f seconds\n", total_time);

    return 0;
}