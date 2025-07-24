//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000  // size of array to be sorted

/* Function to fill an array with random numbers */
void fill_array(int *arr, int n) {
    srand(time(NULL));  // seed the random number generator
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // set each element to a random integer between 0 and 999
    }
}

/* Function to print the contents of an array */
void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to sort an array using insertion sort */
void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    fill_array(arr, ARRAY_SIZE);  // fill array with random numbers
    printf("Unsorted array:\n");
    print_array(arr, ARRAY_SIZE);  // print unsorted array
    clock_t start_time = clock();  // start timer
    insertion_sort(arr, ARRAY_SIZE);  // sort the array
    clock_t end_time = clock();  // end timer
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    print_array(arr, ARRAY_SIZE);  // print sorted array
    printf("Elapsed time: %f seconds\n", elapsed_time);
    return 0;
}