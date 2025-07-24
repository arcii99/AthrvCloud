//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50000000
// Generate an array with random numbers
int* generate_random_array(int size) {
    srand(time(NULL));
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
    return array;
}

// Sum all the elements of an array
int sum_array(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Entry point of the program
int main() {
    int* array = generate_random_array(ARRAY_SIZE);
    // Start measuring time
    clock_t start = clock();
    int sum = sum_array(array, ARRAY_SIZE);
    // Stop measuring time
    clock_t end = clock();
    float time_elapsed = ((float) end - start) / CLOCKS_PER_SEC;
    printf("Sum: %d\n", sum);
    printf("Time elapsed: %f seconds\n", time_elapsed);
    free(array);
    return 0;
}