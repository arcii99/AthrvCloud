//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 100000;
    int arr[size];
    int i, j, temp;

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    clock_t t1, t2;
    double time_taken;

    // Start clock
    t1 = clock();

    // Bubble Sort algorithm
    for (i = 0; i < size; ++i) {
        for (j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Stop clock
    t2 = clock();

    // Calculate time taken
    time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

    printf("Array size: %d\n", size);
    printf("Time taken: %f second(s)\n", time_taken);

    return 0;
}