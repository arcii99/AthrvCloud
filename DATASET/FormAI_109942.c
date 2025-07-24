//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 30000000 // array size
#define LOOP_SIZE 1000000000 // loop size

int main() {
    // generate random array
    int *arr = (int *)malloc(sizeof(int) * ARRAY_SIZE);
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    clock_t start = clock();

    // perform operation
    int result = 0;
    for (int i = 0; i < LOOP_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (arr[j] % 2 == 0) {
                result++;
            }
        }
    }

    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Result: %d\n", result);
    printf("Time taken: %f seconds\n", time_spent);

    free(arr);

    return 0;
}