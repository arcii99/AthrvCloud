//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

/*
 * A simple example program that generates a large array of random numbers,
 * sorts the array using quicksort algorithm, and calculates the sum of all
 * numbers in the sorted array.
 */

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Function to partition array using last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1); // Index of smaller element
 
    for (int j = low; j <= high- 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
 
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int sum = 0;

    // Initialize random number generator
    srand(time(NULL));

    // Fill array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Sort array using quicksort algorithm
    quicksort(arr, 0, ARRAY_SIZE-1);

    // Calculate sum of all elements in the sorted array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += arr[i];
    }

    printf("Sum of all elements in the sorted array is %d\n", sum);

    return 0;
}