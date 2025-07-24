//FormAI DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define NUM_ITERATIONS 1000000

int main() {
    int array[ARRAY_SIZE];
    srand(time(NULL));
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }

    clock_t start_time = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        for (int j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted %d elements %d times in %f seconds\n", ARRAY_SIZE, NUM_ITERATIONS, elapsed_time);

    return 0;
}