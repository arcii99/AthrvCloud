//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10000
#define MAX_VALUE 10000

/* Function declarations */
void bubble_sort(int arr[], int size);
void selection_sort(int arr[], int size); 
void insertion_sort(int arr[], int size);
double measure_time(void (*sort_func)(int [], int), int arr[], int size);

int main() {
    int arr[SIZE];
    int i;

    /* Generate random numbers for the array */
    srand(time(NULL));
    for(i=0; i<SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    /* Measure time for bubble sort and print result */
    double bubble_time = measure_time(bubble_sort, arr, SIZE);
    printf("Time taken for bubble sort: %lf seconds\n", bubble_time);

    /* Measure time for selection sort and print result */
    double selection_time = measure_time(selection_sort, arr, SIZE);
    printf("Time taken for selection sort: %lf seconds\n", selection_time);

    /* Measure time for insertion sort and print result */
    double insertion_time = measure_time(insertion_sort, arr, SIZE);
    printf("Time taken for insertion sort: %lf seconds\n", insertion_time);

    return 0;
}

/* Function to implement bubble sort algorithm */
void bubble_sort(int arr[], int size) {
    int i, j, temp;
    for(i=0; i<size-1; i++) {
        for(j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* Function to implement selection sort algorithm */
void selection_sort(int arr[], int size) {
    int i, j, min_idx, temp;
    for(i=0; i<size-1; i++) {
        min_idx = i;
        for(j=i+1; j<size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

/* Function to implement insertion sort algorithm */
void insertion_sort(int arr[], int size) {
    int i, j, key;
    for(i=1; i<size; i++) {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

/* Function to measure the time taken for a sorting algorithm to process an array */
double measure_time(void (*sort_func)(int [], int), int arr[], int size) {
    clock_t start_time, end_time;
    start_time = clock();
    (*sort_func)(arr, size);
    end_time = clock();

    return ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}