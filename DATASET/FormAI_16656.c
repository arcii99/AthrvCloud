//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define the number of elements to be sorted
    int n = 500000;

    // Allocate memory for the array to be sorted
    int *arr = (int*) malloc(n * sizeof(int));

    // Fill the array with random integers between 1 and 100
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Start the timer
    clock_t start_time = clock();

    // Apply bubble sort algorithm to sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // End the timer
    clock_t end_time = clock();
    double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Display the sorted array and the time taken to sort it
    printf("Array sorted successfully in %lf seconds:\n", time_elapsed);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}