//FormAI DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Puzzle: Generate an array of random integers and sort them using bubble sort algorithm.
// Measure the time it takes to sort the array and compare it with selection sort algorithm.

#define SIZE 10000

// Bubble sort algorithm to sort the array in ascending order
void bubble_sort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection sort algorithm to sort the array in ascending order
void selection_sort(int arr[], int size) {
    int i, j, min_idx;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    // Generate random array of integers
    int arr[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    
    // Sort the array using bubble sort algorithm and measure its time
    clock_t start_bubble = clock();
    bubble_sort(arr, SIZE);
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
    
    // Sort the array using selection sort algorithm and measure its time
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    clock_t start_selection = clock();
    selection_sort(arr, SIZE);
    clock_t end_selection = clock();
    double time_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;
    
    // Print the time taken by each algorithm
    printf("Bubble sort took %lf seconds to sort the array of size %d.\n", time_bubble, SIZE);
    printf("Selection sort took %lf seconds to sort the same array.\n", time_selection);
    
    return 0;
}