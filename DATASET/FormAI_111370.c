//FormAI DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers
void generate_random_numbers(int arr[], int size) {
    srand(time(NULL)); // setting random seed
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1; // generating numbers between 1 and 100
    }
}

// function to display the array
void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to do bubble sort
void bubble_sort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// function to do selection sort
void selection_sort(int arr[], int size) {
    int min_index, temp;
    for (int i = 0; i < size - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int size = 10000;
    int arr[size];

    // generating random numbers
    generate_random_numbers(arr, size);

    // displaying unsorted array
    printf("Unsorted Array:\n");
    display_array(arr, size);

    // benchmarking bubble sort
    clock_t start = clock();
    bubble_sort(arr, size);
    clock_t end = clock();

    // displaying sorted array
    printf("Sorted Array using Bubble Sort:\n");
    display_array(arr, size);

    // calculating time taken for bubble sort
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for Bubble Sort: %f seconds\n", time_taken);

    // generating random numbers again
    generate_random_numbers(arr, size);

    // displaying unsorted array
    printf("Unsorted Array:\n");
    display_array(arr, size);

    // benchmarking selection sort
    start = clock();
    selection_sort(arr, size);
    end = clock();

    // displaying sorted array
    printf("Sorted Array using Selection Sort:\n");
    display_array(arr, size);

    // calculating time taken for selection sort
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for Selection Sort: %f seconds\n", time_taken);

    return 0;
}