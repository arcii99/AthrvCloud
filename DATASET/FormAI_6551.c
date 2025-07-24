//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

/*
 * This program generates an array of random integers and sorts it using insertion sort.
 * The program also calculates the time taken to sort the array and prints it to the console.
 */

void insertion_sort(int arr[], int n) { 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(NULL)); // Seed random number generator with current time

    // Generate array of random integers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % ARRAY_SIZE;
    }

    // Calculate time taken to sort array using insertion sort
    clock_t start_time = clock();
    insertion_sort(arr, ARRAY_SIZE);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print sorted array and time taken to sort
    printf("Array sorted using Insertion Sort Algorithm\n\n");
    printf("Sorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nTime taken to sort: %f seconds", time_taken);

    return 0;
}