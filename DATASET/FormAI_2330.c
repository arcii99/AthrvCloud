//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number within a range
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to sort an integer array using Bubble sort algorithm
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to check if an array is sorted in ascending order
int is_sorted(int arr[], int n) {
    int i;
    for(i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1])
            return 0; // Return 0 if array is not sorted
    }
    return 1; // Return 1 if array is sorted
}

int main() {
    int n = 10000; // Size of the array
    int arr[n];
    int i;
    clock_t start, end;
    double cpu_time_used;

    // Generate a random array of integers between 0 and 99
    srand(time(NULL));
    for(i = 0; i < n; i++) {
        arr[i] = generate_random_number(0, 99);
    }

    // Sort the array using bubble sort algorithm
    start = clock();
    bubble_sort(arr, n);
    end = clock();

    // Compute the time taken by the bubble sort algorithm
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Check if the array is sorted
    if(is_sorted(arr, n)) {
        printf("Array is sorted in ascending order.\n");
        printf("Time taken by bubble sort to sort the array: %f seconds.\n", cpu_time_used);
    } else {
        printf("Array is not sorted.\n");
    }

    return 0;
}