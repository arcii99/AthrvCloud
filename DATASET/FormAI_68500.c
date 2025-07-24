//FormAI DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

// Function to initialize an array with random values
void initialize_array(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print an array
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble sort algorithm for sorting an array in ascending order
void bubble_sort(int* arr, int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];
    clock_t start, end;
    double total_time;

    // Initialize the array with random values
    initialize_array(arr, SIZE);

    printf("Original array:\n");
    print_array(arr, SIZE);

    // Start measuring the sorting time
    start = clock();
    
    // Sort the array using bubble sort algorithm
    bubble_sort(arr, SIZE);
    
    // Measure the elapsed time
    end = clock();
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    print_array(arr, SIZE);
    
    printf("\nTotal sorting time: %f seconds\n", total_time);

    return 0;
}