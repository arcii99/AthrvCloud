//FormAI DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int array[SIZE];

int main() {

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    int sum = 0;
    clock_t start = clock();

    // Calculating sum using for loop
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    clock_t end = clock();

    double time_spent = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Using for loop, sum = %d\n", sum);
    printf("Time taken: %f seconds\n", time_spent);

    sum = 0;
    start = clock();

    // Calculating sum using while loop
    int i = 0;
    while (i < SIZE) {
        sum += array[i];
        i++;
    }

    end = clock();

    time_spent = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Using while loop, sum = %d\n", sum);
    printf("Time taken: %f seconds\n", time_spent);

    return 0;
}