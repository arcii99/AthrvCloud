//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

// This function will shuffle an array of integers using the Fisher-Yates shuffle algorithm
void shuffle_array(int *array, int size) {
    srand((unsigned) time(NULL));   // Seed the random number generator
    for (int i = size-1; i > 0; i--) {
        int j = rand() % (i+1);     // Pick a random index from 0 to i
        // Swap the elements at indices i and j
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// This function will sort an array of integers using the bubble sort algorithm
void bubble_sort(int *array, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                // Swap the elements at indices j and j+1
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int array[ARRAY_SIZE];
    // Populate the array with numbers from 1 to ARRAY_SIZE
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i+1;
    }
    // Shuffle the array
    shuffle_array(array, ARRAY_SIZE);
    // Sort the array using bubble sort and measure the time it takes
    clock_t start = clock();
    bubble_sort(array, ARRAY_SIZE);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);
    return 0;
}