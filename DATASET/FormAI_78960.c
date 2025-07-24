//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 1000000

int main() {

    int i, j, sum = 0;
    int arr[SIZE];

    // Fill array with random values
    srand(time(NULL));
    for(i = 0; i < SIZE; i++){
        arr[i] = rand() % 10000;
    }

    // Benchmarking the program using clock()
    clock_t start = clock();

    // Loop through the array to calculate sum
    for(i = 0; i < SIZE; i++){
        sum += arr[i];
    }

    // Print sum
    printf("The sum of the array is: %d\n", sum);

    // End clock
    clock_t end = clock();

    // Calculate time elapsed
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print time elapsed
    printf("Time elapsed: %f seconds\n", elapsed_time);

    return 0;
}