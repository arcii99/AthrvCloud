//FormAI DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program implements an optimized bubble sort algorithm for sorting arrays of integers */

void bubble_sort(int *arr, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main() {
    int arr[10] = {5, 7, 3, 9, 1, 8, 4, 6, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Print the array before sorting
    printf("Before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array using the optimized bubble sort algorithm
    bubble_sort(arr, size);
    
    // Print the array after sorting
    printf("After sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}