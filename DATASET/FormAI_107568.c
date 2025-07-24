//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 5000

int main()
{
    int i, j, temp;
    int arr[COUNT];
    clock_t start, end;

    // Filling the array with random numbers
    srand(time(NULL));
    for (i = 0; i < COUNT; i++) {
        arr[i] = rand() % 100;
    }

    // Printing the original array
    printf("Original Array:\n");
    for (i = 0; i < COUNT; i++) {
        printf("%d ", arr[i]);
    }

    // Starting the timer
    start = clock();

    // Sorting the array using Bubble Sort algorithm
    for (i = 0; i < COUNT-1; i++) {
        for (j = 0; j < COUNT-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Stopping the timer
    end = clock();

    // Printing the sorted array and time taken
    printf("\nSorted Array:\n");
    for (i = 0; i < COUNT; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}