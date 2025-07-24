//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000 // A very large array size
#define ITERATIONS 1000000   // A very large number of iterations

int main()
{
    int *array;
    int i, j, tmp;
    clock_t t1, t2;
    
    array = (int*) malloc(sizeof(int) * ARRAY_SIZE); // Allocate memory for the very large array

    // Populate the array with random values
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Start the timer
    t1 = clock();

    // A very performance-critical component: sorting the array using bubble sort
    for (i = 0; i < ITERATIONS; i++) {
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }

    // Stop the timer
    t2 = clock();

    // Print the elapsed time
    printf("Elapsed time: %f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    // Free the memory
    free(array);

    return 0;
}