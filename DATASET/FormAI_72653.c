//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to generate random numbers between 0 and 100
int random_num() {
    return rand() % 101;
}

int main() {
    int i;
    int a[ARRAY_SIZE];
    srand(time(NULL));

    // populate the array with random numbers
    for(i = 0; i < ARRAY_SIZE; i++) {
        a[i] = random_num();
    }

    // calculate the sum of all the numbers in the array
    int sum = 0;
    clock_t start_time = clock();
    for(i = 0; i < ARRAY_SIZE; i++) {
        sum += a[i];
    }
    printf("Sum of all elements in array: %d\n", sum);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken for operation: %f seconds", time_taken);
    return 0;
}