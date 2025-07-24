//FormAI DATASET v1.0 Category: Sorting ; Style: thoughtful
/* 
A sorting program that takes an array of integers as input 
and sorts them in ascending order using the bubble sort algorithm.
The program uses user-defined functions for sorting and for printing 
the sorted array.
*/

#include <stdio.h>

// Function to swap two elements in an array
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort function to sort the given array
void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to print the sorted array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // input array
    int arr[] = {5, 2, 9, 10, 4, 7};
    // no. of elements in the array
    int n = sizeof(arr) / sizeof(int);

    printf("Input array:\n");
    print_array(arr, n);

    // sort the array using bubble sort
    bubble_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}