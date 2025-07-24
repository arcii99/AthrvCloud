//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main(void) {
    double start_time, end_time;
    int *array = malloc(sizeof(int) * SIZE); 

    // Fill the array with random integers
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Find the maximum value in the array
    start_time = clock();
    int max_value = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    end_time = clock();

    printf("The maximum value in the array is %d.\n", max_value);
    printf("Execution time: %f seconds.", (end_time - start_time) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}