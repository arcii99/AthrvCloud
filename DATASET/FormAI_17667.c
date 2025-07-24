//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Surprising C Performance-Critical Component Example Program!\n");

    // Set up random number generator
    srand(time(NULL));

    // Initialize large arrays
    int* arr1 = malloc(1000000 * sizeof(int));
    int* arr2 = malloc(1000000 * sizeof(int));

    // Populate large arrays with random numbers
    for(int i = 0; i < 1000000; i++) {
        arr1[i] = rand();
        arr2[i] = rand();
    }

    // Start timer
    clock_t start_time = clock();

    // Perform some computation on large arrays
    long long sum = 0;
    for(int i = 0; i < 1000000; i++) {
        sum += arr1[i] * arr2[i];
    }

    // End timer
    clock_t end_time = clock();

    // Print results
    printf("Computed sum: %lld\n", sum);
    printf("Elapsed time: %f seconds\n", ((double)(end_time - start_time))/CLOCKS_PER_SEC);

    // Deallocate memory
    free(arr1);
    free(arr2);

    return 0;
}