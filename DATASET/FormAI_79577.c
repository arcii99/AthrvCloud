//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define NUM_ROUNDS 100

int main()
{
    int array[ARRAY_SIZE];
    int i, j, temp;
    clock_t start, end;
    double total_time;
    
    //initialize the array with random numbers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand();
    }

    //sort the array using bubble sort
    start = clock();
    for (i = 0; i < NUM_ROUNDS; i++) {
        for (j = 0; j < ARRAY_SIZE-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    
    //calculate the total time taken for sorting
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Time taken to sort the array using bubble sort for %d rounds: %f seconds\n", NUM_ROUNDS, total_time);

    return 0;
}