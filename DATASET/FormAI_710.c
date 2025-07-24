//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20000

int main() {
    int arr[SIZE];
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL)); // Seed the random number generator

    // Fill the array with random numbers
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted array: \n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    start = clock(); // Start the clock

    // Perform bubble sort on the array
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    end = clock(); // Stop the clock
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the time taken
    printf("Sorted array: \n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);

    return 0;
}