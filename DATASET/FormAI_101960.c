//FormAI DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define ARRAY_SIZE 1000000

void generate_random_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000 + 1;
    }
}

void print_array(int *array, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[i+1];
        array[i+1] = array[high];
        array[high] = temp;

        int mid = i + 1;

        quick_sort(array, low, mid-1);
        quick_sort(array, mid+1, high);
    }
}

int binary_search(int *array, int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int array[ARRAY_SIZE];
    clock_t start_time, end_time;
    generate_random_array(array, ARRAY_SIZE);

    printf("Array before sorting\n");
    print_array(array, ARRAY_SIZE);

    // Bubble Sort
    printf("Bubble Sort\n");
    start_time = clock();
    bubble_sort(array, ARRAY_SIZE);
    end_time = clock();
    printf("Time taken: %f seconds\n", ((double) (end_time - start_time)) / CLOCKS_PER_SEC);
    printf("Array after sorting\n");
    print_array(array, ARRAY_SIZE);

    // Quick Sort
    printf("Quick Sort\n");
    generate_random_array(array, ARRAY_SIZE);
    start_time = clock();
    quick_sort(array, 0, ARRAY_SIZE-1);
    end_time = clock();
    printf("Time taken: %f seconds\n", ((double) (end_time - start_time)) / CLOCKS_PER_SEC);
    printf("Array after sorting\n");
    print_array(array, ARRAY_SIZE);

    // Binary Search
    printf("Binary Search\n");
    int target = array[500000]; // Choose random number from array
    printf("Target: %d\n", target);
    start_time = clock();
    int index = binary_search(array, ARRAY_SIZE, target);
    end_time = clock();
    if (index == -1) {
        printf("Target not found\n");
    } else {
        printf("Target found at index: %d\n", index);
    }
    printf("Time taken: %f seconds\n", ((double) (end_time - start_time)) / CLOCKS_PER_SEC);

    return 0;
}