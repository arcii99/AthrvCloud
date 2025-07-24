//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <time.h>

#define NUM_ELEMENTS 1000000  // Define the number of elements to be sorted

// Define a simple swap macro to be used later on
#define SWAP(x, y) { int temp = x; x = y; y = temp; }

// Function to perform a simple bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                SWAP(arr[j], arr[j+1]);
            }
        }
    }
}

// Main function to run the benchmarking program
int main() {
    int arr[NUM_ELEMENTS];  // Declare an array of integers of size NUM_ELEMENTS
    int i;
    double start_time, end_time, elapsed_time;  // Declare variables to measure the time

    // Initialize the array with random elements between 1 and 1000
    for (i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    // Measure the time it takes to sort the array using bubble sort
    start_time = (double) clock() / CLOCKS_PER_SEC;  // Get the current time in seconds
    bubbleSort(arr, NUM_ELEMENTS);
    end_time = (double) clock() / CLOCKS_PER_SEC;  // Get the current time in seconds

    // Calculate the elapsed time
    elapsed_time = end_time - start_time;

    // Print the sorted array and the elapsed time
    printf("Sorted array: \n");
    for (i = 0; i < NUM_ELEMENTS; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nElapsed time: %.4f seconds\n", elapsed_time);

    return 0;
}