//FormAI DATASET v1.0 Category: Benchmarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int arr[ARRAY_SIZE];
    int i, j, temp;
    clock_t start, end;

    // Fill the array with random numbers
    srand((unsigned) time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % ARRAY_SIZE;
    }
  
    // Print the unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Benchmark the bubble sort algorithm
    start = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the time taken
    printf("Bubble sort time: %.4f seconds\n", time_taken);
 
    return 0;
}