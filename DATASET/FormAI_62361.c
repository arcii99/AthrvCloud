//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 100000000
#define MIN_NUM 1
#define MAX_NUM 100

int main() {
    int arr[ARR_SIZE];
    int i, j, temp;

    // Initialize the array with random integers between 1 and 100
    srand(time(NULL));
    for (i = 0; i < ARR_SIZE; i++) {
        arr[i] = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
    }

    // Benchmarking starts here
    clock_t start_time, end_time;
    double total_time;

    start_time = clock();

    // Bubble Sort Algorithm
    for (i = 0; i < ARR_SIZE; i++) {
        for (j = 0; j < ARR_SIZE-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    end_time = clock();
    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d integers using bubble sort algorithm: %f seconds\n", ARR_SIZE, total_time);

    return 0;
}