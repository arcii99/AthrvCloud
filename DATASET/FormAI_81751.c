//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50000

/**
 * Function to populate an array with random integers from 0 to 9999
 * @param arr array to be populated
 */
void populate_array(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 10000;
    }
}

/**
 * Function to print an array
 * @param arr array to be printed
 */
void print_array(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Function to perform a bubble sort on an array of integers
 * @param arr array to be sorted
 */
void bubble_sort(int arr[]) {
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;
            }
        }
    }
}

/**
 * Function to perform a quick sort on an array of integers
 * @param arr array to be sorted
 * @param left leftmost index of the array to be sorted
 * @param right rightmost index of the array to be sorted
 */
void quick_sort(int arr[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) {
        quick_sort(arr, left, j);
    }
    if (i < right) {
        quick_sort(arr, i, right);
    }
}

int main() {
    int arr[ARRAY_SIZE];
    clock_t start, end;
    double bubble_sort_time, quick_sort_time;

    printf("Populating array...\n");
    populate_array(arr);
    printf("Sorting array using bubble sort...\n");
    start = clock();
    bubble_sort(arr);
    end = clock();
    bubble_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %f seconds\n\n", bubble_sort_time);

    printf("Populating array...\n");
    populate_array(arr);
    printf("Sorting array using quick sort...\n");
    start = clock();
    quick_sort(arr, 0, ARRAY_SIZE - 1);
    end = clock();
    quick_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort: %f seconds\n\n", quick_sort_time);

    return 0;
}