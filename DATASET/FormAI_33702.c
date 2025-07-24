//FormAI DATASET v1.0 Category: Sorting ; Style: protected
// This program sorts an array of integers in ascending order using selection sort algorithm

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void selection_sort(int* arr, int size);

int main() {
    int arr[ARRAY_SIZE] = {7, 3, 9, 2, 5, 1, 8, 6, 4, 0};
    int i;

    // print the unsorted array
    printf("Unsorted array: [ ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    // sort the array
    selection_sort(arr, ARRAY_SIZE);

    // print the sorted array
    printf("Sorted array: [ ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    return 0;
}

void selection_sort(int* arr, int size) {
    int i, j, tmp, min_idx;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // swap the minimum element with the current element
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}