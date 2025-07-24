//FormAI DATASET v1.0 Category: Benchmarking ; Style: ephemeral
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 100000

int main() {

    int array[ARRAY_SIZE];
    int i, j, temp;
    clock_t start, end;
    double time_taken;

    // fill the array with random integers
    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }

    start = clock(); // start the timer

    // perform bubble sort
    for(i = 0; i < ARRAY_SIZE-1; i++) {
        for(j = 0; j < ARRAY_SIZE-i-1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    end = clock(); // stop the timer

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate the time taken

    printf("Sorted Array:\n");

    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    printf("\nTime taken for sorting: %lf seconds", time_taken);

    return 0;
}