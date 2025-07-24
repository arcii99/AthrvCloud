//FormAI DATASET v1.0 Category: Benchmarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

// Function to fill an array with random numbers
void fillArray(int array[], int size) {
    srand(time(NULL)); // Seed random generator
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Generate random number between 0 and 999
    }
}

// Bubble sort algorithm
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                // Swap elements
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int array[SIZE];
    fillArray(array, SIZE);
    
    clock_t start_time, end_time;
    double cpu_time_used;
    start_time = clock();
    
    bubbleSort(array, SIZE);
    
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
  
    printf("Sorting took %f seconds.\n", cpu_time_used);
    return 0;
}