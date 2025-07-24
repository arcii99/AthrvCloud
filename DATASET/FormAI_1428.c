//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubble_sort(int arr[], int arr_size) {
    int temp;
    for(int i = 0; i < arr_size - 1; i++) {
        for(int j = 0; j < arr_size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int arr_size) {
    int i, j, min_idx, temp;
    for(i = 0; i < arr_size-1; i++) {
        min_idx = i;
        for(j = i+1; j < arr_size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr1[ARRAY_SIZE], arr2[ARRAY_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Generating random numbers for the array
    srand(time(NULL));
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr1[i] = rand() % ARRAY_SIZE;
        arr2[i] = arr1[i];
    }

    // Benchmarking Bubble Sort
    printf("Bubble sort benchmarking started...\n");
    start = clock();
    bubble_sort(arr1, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort benchmarking completed in %lf seconds\n\n", cpu_time_used);

    // Benchmarking Selection Sort
    printf("Selection sort benchmarking started...\n");
    start = clock();
    selection_sort(arr2, ARRAY_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort benchmarking completed in %lf seconds\n", cpu_time_used);

    return 0;
}