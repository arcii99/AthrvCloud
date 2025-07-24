//FormAI DATASET v1.0 Category: Benchmarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 1000000

// Function to initialize an array with random data
void init_array(int arr[]) {
    srand(time(NULL));
    for (int i = 0; i < DATA_SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

// Bubble sort algorithm
void bubble_sort(int arr[]) {
    int temp;
    for (int i = 0; i < DATA_SIZE-1; i++) {
        for (int j = 0; j < DATA_SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int data[DATA_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Initialize the array with random data
    init_array(data);

    // Start measuring time
    start = clock();

    // Sort the array using bubble sort
    bubble_sort(data);

    // End measuring time
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d integers using bubble sort: %f seconds\n", DATA_SIZE, cpu_time_used);

    return 0;
}