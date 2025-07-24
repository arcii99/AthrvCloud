//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>

/* This program demonstrates a performance-critical component: sorting an array
   of integers using the quicksort algorithm. */

/* This function takes in an array of integers, a starting index, and an ending 
   index. It partitions the array such that all elements less than the pivot
   are left of the pivot, and all elements greater than or equal to the pivot
   are to the right of the pivot. It then returns the index of the pivot. */
int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return i+1;
}

/* This function takes in an array of integers, a starting index, and an ending
   index. It sorts the subarray between the starting and ending indices using
   the quicksort algorithm. */
void quicksort(int *arr, int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end);
        quicksort(arr, start, pi-1);
        quicksort(arr, pi+1, end);
    }
}

int main() {
    int arr[] = {3, 7, 1, 4, 9, 2, 5, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n-1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}