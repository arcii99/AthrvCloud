//FormAI DATASET v1.0 Category: Benchmarking ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// A function to fill an array with random integers
void fill_array(int arr[], int size) {
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 1000000;
}

// A function to print an array
void print_array(int arr[], int size) {
    printf("[ ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

// A function to bubble sort an array
void bubble_sort(int arr[], int size) {
    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for(int i = 0; i < size-1; i++) {
            if(arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = false;
            }
        }
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Declare array and fill with random integers
    int arr[ARRAY_SIZE];
    fill_array(arr, ARRAY_SIZE);

    // Print unsorted array
    printf("Unsorted array:\n");
    print_array(arr, ARRAY_SIZE);

    // Record start time
    clock_t start = clock();

    // Sort the array
    bubble_sort(arr, ARRAY_SIZE);

    // Record end time
    clock_t end = clock();

    // Print sorted array
    printf("Sorted array:\n");
    print_array(arr, ARRAY_SIZE);

    // Calculate and print duration
    printf("Sorting took %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}