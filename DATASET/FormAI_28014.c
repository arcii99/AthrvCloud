//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, arr[ARRAY_SIZE];
    clock_t start_time, end_time;
    double time_diff;

    // Generate a random array
    srand(time(NULL)); // set the random seed
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000; // random number between 0 and 999
    }

    // Measure the time it takes to sort the array
    start_time = clock(); // get the start time
    bubble_sort(arr, ARRAY_SIZE); // sort the array
    end_time = clock(); // get the end time

    // Calculate the time difference
    time_diff = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Print the sorted array and the time it took to sort it
    printf("Sorted array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken: %f seconds\n", time_diff);

    return 0;
}