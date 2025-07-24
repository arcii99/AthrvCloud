//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a lot of random integers and sorts them in descending order, using a quicksort algorithm. 
It's performance-critical because it has to handle a large amount of data very quickly. */

#define MAX_SIZE 1000000

void print_array(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] >= pivot) {
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

void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int pivot_idx = partition(arr, start, end);
        quicksort(arr, start, pivot_idx-1);
        quicksort(arr, pivot_idx+1, end);
    }
}

int main() {
    int num_array[MAX_SIZE];

    // generate random integers
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        num_array[i] = rand() % 10000;
    }

    // sort the array
    quicksort(num_array, 0, MAX_SIZE-1);

    printf("Sorted array:\n");
    print_array(num_array, MAX_SIZE);

    return 0;
}