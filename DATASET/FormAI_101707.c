//FormAI DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int array[SIZE];
    clock_t start, end;
    double time_taken;

    // Generate random numbers and fill array
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Insertion sort algorithm
    start = clock();
    for(int i = 1; i < SIZE; i++) {
        int j = i;
        while(j > 0 && array[j - 1] > array[j]) {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print sorted array and time taken
    printf("Sorted array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}