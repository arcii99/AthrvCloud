//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 100000

int main() {
    int arr[ARRAY_SIZE];

    // Populate the array with random integers between 0 and 99
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Start measuring the time for this code block
    clock_t t = clock();

    // Perform a simple sorting algorithm - Bubble Sort
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // End measuring the time for this code block
    t = clock() - t;

    // Print the sorted array and the time it took to sort it
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nBubble sort took %f seconds to sort an array of size %d.\n", 
           ((float)t) / CLOCKS_PER_SEC, ARRAY_SIZE);

    return 0;
}