//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the array with random values
void initialize_array(int arr[], int size) {
    srand(time(NULL));  // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Generate a random number between 0 and 999 for each element
    }
}

// Function to print the array on the console
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using bubble sort algorithm
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size = 10000;
    int arr[size];

    initialize_array(arr, size);

    printf("Unsorted array:\n");
    print_array(arr, size);

    clock_t start = clock();
    bubble_sort(arr, size);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    print_array(arr, size);

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}