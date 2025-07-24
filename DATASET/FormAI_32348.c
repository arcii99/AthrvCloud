//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array[1000000];
    clock_t start, end;
    double cpu_time_used;

    // Fill the array with random numbers
    for (int i = 0; i < 1000000; i++) {
        array[i] = rand();
    }

    // Benchmark sorting the array using bubble sort
    start = clock();
    for (int i = 0; i < 999999; i++) {
        for (int j = 0; j < 999999-i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted 1,000,000 random integers using bubble sort in %f seconds!\n", cpu_time_used);

    return 0;
}