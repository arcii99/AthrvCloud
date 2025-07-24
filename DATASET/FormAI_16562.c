//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int i, j;
    int temp;
    int data[ARRAY_SIZE];

    // Generate random data
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        data[i] = rand();
    }

    // Bubble sort algorithm
    clock_t start = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();

    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds.\n", time_taken);

    // Selection sort algorithm
    start = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        temp = data[min_idx];
        data[min_idx] = data[i];
        data[i] = temp;
    }
    end = clock();

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort took %f seconds.\n", time_taken);

    return 0;
}