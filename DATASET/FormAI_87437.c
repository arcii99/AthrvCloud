//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5000000

void populate_array(int* array, int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 100; // generate numbers between 0 - 99
    }
}

void bubble_sort(int* array, int size) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j+1]) {
                // swap
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int array1[ARRAY_SIZE];
    populate_array(array1, ARRAY_SIZE);
    
    int array2[ARRAY_SIZE];
    populate_array(array2, ARRAY_SIZE);
    
    // Unoptimized bubble sort
    clock_t start = clock(); // measure time taken
    bubble_sort(array1, ARRAY_SIZE);
    clock_t end = clock(); // measure time taken
    
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Unoptimized bubble sort took %f seconds\n", execution_time);
    
    // Optimized bubble sort
    start = clock(); // measure time taken
    bubble_sort(array2, ARRAY_SIZE);
    end = clock(); // measure time taken
    
    execution_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Optimized bubble sort took %f seconds\n", execution_time);
    
    return 0;
}