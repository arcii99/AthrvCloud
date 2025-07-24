//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000 // Define the size of the array
#define LOOP_COUNT 10000 // Number of times the loop needs to be executed

int main() {
    srand(time(NULL)); // Seed the random number generator
 
    // Create an array of random integers between 1 and 999
    int array[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 999 + 1;
    }

    // Start the timer
    clock_t start = clock();

    // Perform bubble sort on the array
    for(int i = 0; i < LOOP_COUNT; i++) {
        for(int j = 0; j < ARRAY_SIZE - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // End the timer and calculate the duration
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the first and last elements of the sorted array to confirm it's sorted
    printf("First element: %d\n", array[0]);
    printf("Last element: %d\n", array[ARRAY_SIZE - 1]);

    // Print the duration of the sort loop
    printf("Duration: %f seconds\n", duration);

    return 0;
}