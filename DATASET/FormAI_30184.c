//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to generate a random number between given range
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to initialize an array with random values
void init_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = get_random_number(1, 100);
    }
}

// Function to perform bubble sort on an array
void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the time taken by a function to execute
double measure_execution_time(void (*function)(int[], int), int array[], int size) {
    clock_t start = clock();
    function(array, size);
    clock_t end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// Main function to test the benchmarking
int main() {
    int array[ARRAY_SIZE];
    init_array(array, ARRAY_SIZE);

    printf("===== Benchmarking Bubble Sort =====\n");
    double bubble_sort_time = measure_execution_time(&bubble_sort, array, ARRAY_SIZE);
    printf("Time taken by Bubble Sort: %lf seconds\n", bubble_sort_time);

    return 0;
}