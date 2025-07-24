//FormAI DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

int main(int argc, char *argv[]) {
    int arr[ARR_SIZE];
    clock_t start_t, end_t;
    double cpu_time_used;

    // Populate the array with random numbers
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Starting sorting algorithm...\n");
    start_t = clock();

    // Insertion sort
    for (int i = 1; i < ARR_SIZE; i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }

    end_t = clock();
    printf("Sorting completed!\n");

    cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;
    printf("CPU time used: %f seconds\n", cpu_time_used);
    return 0;
}