//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

//This example program generates an array of 100 random integers between 0-100 and then sorts the array using the Quick Sort algorithm.

void print_array(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[ARRAY_SIZE];

    //Seed the random number generator using the system clock
    srand(time(NULL));

    //Generate an array of 100 random integers between 0-100
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted Array: ");
    print_array(arr, ARRAY_SIZE);

    //Sort the array using the Quick Sort algorithm
    quick_sort(arr, 0, ARRAY_SIZE - 1);

    printf("Sorted Array: ");
    print_array(arr, ARRAY_SIZE);

    return 0;
}