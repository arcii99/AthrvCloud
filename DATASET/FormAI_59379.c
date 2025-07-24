//FormAI DATASET v1.0 Category: Benchmarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int* array = malloc(sizeof(int) * ARRAY_SIZE);
    if (array == NULL) {
        printf("Failed to allocate memory for the array!");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    clock_t start = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int sum = 0;
        for (int j = 0; j < 1000; j++) {
            sum += array[i+j];
        }
    }
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sum 1000 adjacent numbers in a %d element array: %f seconds", ARRAY_SIZE, time_spent);

    free(array);
    return 0;
}