//FormAI DATASET v1.0 Category: Benchmarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int array[MAX_SIZE];
    int sum = 0;
    double time_spent = 0.0;

    // Populate array with random numbers
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        array[i] = rand() % 100;
    }

    clock_t begin = clock();

    // Calculate the sum of the array elements
    for (int i = 0; i < MAX_SIZE; i++) {
        sum += array[i];
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The sum of the array elements is %d.\n", sum);
    printf("Time elapsed: %f seconds.\n", time_spent);

    return 0;
}