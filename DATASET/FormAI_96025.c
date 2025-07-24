//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000 // define a maximum size of an array filled with random integers

// Function to generate random integers and store them in an array
void generate_random_numbers(int* arr, int size) {
    srand(time(NULL)); // seed the random number generator
    
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size; // generate random number between 0 and size-1
    }
}

// Function to sort an array of integers in ascending order using bubble sort algorithm
void bubble_sort(int* arr, int size) {
    int temp;
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_NUMBERS];
    generate_random_numbers(arr, MAX_NUMBERS);

    clock_t start_time = clock(); // mark the start time
    bubble_sort(arr, MAX_NUMBERS);
    clock_t end_time = clock(); // mark the end time

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}