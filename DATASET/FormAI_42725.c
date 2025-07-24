//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Generate a random array of integers
void generate_random_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Copy array1 into array2
void copy_array(int *array1, int *array2, int size) {
    for (int i = 0; i < size; i++) {
        array2[i] = array1[i];
    }
}

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Perform bubble sort on the array
void bubble_sort(int *arr, int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

// Perform quick sort on the array
void quick_sort(int *arr, int left, int right) {
    int i, j, pivot;
    if (left < right) {
        pivot = arr[left];
        i = left;
        j = right;
        while (i < j) {
            while (arr[i] <= pivot && i < right) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(&arr[i], &arr[j]);
            }
        }
        arr[left] = arr[j];
        arr[j] = pivot;
        quick_sort(arr, left, j - 1);
        quick_sort(arr, j + 1, right);
    }
}

// Compare the performance of bubble sort and quick sort on a large array
int main() {
    int arr1[ARRAY_SIZE];
    int arr2[ARRAY_SIZE];
    generate_random_array(arr1, ARRAY_SIZE);
    copy_array(arr1, arr2, ARRAY_SIZE);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bubble_sort(arr1, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f\n", cpu_time_used);

    start = clock();
    quick_sort(arr2, 0, ARRAY_SIZE - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: %f\n", cpu_time_used);

    return 0;
}