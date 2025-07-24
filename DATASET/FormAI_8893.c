//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cryptic
// C Benchmarking Example Program (Cryptic Style)
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE 1000000

int main(void) {
    struct timeval t1, t2;

    // Allocate memory
    int *arr = (int *) malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Generate random values for the array
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Get starting time
    gettimeofday(&t1, NULL);

    // Perform some time-consuming task
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i] * arr[i];
    }

    // Get ending time
    gettimeofday(&t2, NULL);

    // Display the result and the time taken to execute the task
    double time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Result: %d\n", sum);
    printf("Time taken: %f seconds", time_taken);

    // Free the allocated memory
    free(arr);

    return 0;
}