//FormAI DATASET v1.0 Category: Benchmarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000


// Function to initialize the array with random numbers
void initializeArray(int* array) {
    srand(time(NULL));
    for(int i=0; i<ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
}


// Function to perform bubble sort on the array
void bubbleSort(int* array) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        for(int j=0; j<ARRAY_SIZE-i-1; j++) {
            if(array[j] > array[j+1]) {
                // swap the elements
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


// Function to perform selection sort on the array
void selectionSort(int* array) {
    for(int i=0; i<ARRAY_SIZE-1; i++) {
        int min_index = i;
        for(int j=i+1; j<ARRAY_SIZE; j++) {
            if(array[j] < array[min_index]) {
                min_index = j;
            }
        }
        // swap the elements
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}


int main() {
    int array[ARRAY_SIZE];

    // initialize the array with random numbers
    initializeArray(array);

    // calculate the time taken to perform bubble sort
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    bubbleSort(array);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to perform bubble sort: %f seconds\n", cpu_time_used);

    // initialize the array again with random numbers
    initializeArray(array);

    // calculate the time taken to perform selection sort
    start = clock();
    selectionSort(array);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to perform selection sort: %f seconds\n", cpu_time_used);

    return 0;
}