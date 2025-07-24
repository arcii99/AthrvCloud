//FormAI DATASET v1.0 Category: Benchmarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

/* Function to populate an array with random integers */
void populate_array(int *array, int size) {
    srand(time(NULL)); // Initialize the seed for random number generator
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

/* Function to print an array */
void print_array(int *array, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

/* Function to perform bubble sort on an array of integers */
void bubble_sort(int *array, int size) {
    int temp;
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                /* Swap two adjacent elements */
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/* Main function */
int main() {
    int data[ARRAY_SIZE];
    populate_array(data, ARRAY_SIZE);

    printf("Before sorting:\n");
    print_array(data, ARRAY_SIZE);

    clock_t begin = clock(); // Start the timer

    bubble_sort(data, ARRAY_SIZE);

    clock_t end = clock(); // Stop the timer

    printf("After sorting:\n");
    print_array(data, ARRAY_SIZE);

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds", time_spent);

    return 0;
}