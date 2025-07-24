//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int array[ARRAY_SIZE];
    int i;
    
    // seed random number generator
    srand(time(NULL));
    
    // fill array with random ints
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
    
    // time bubble sort
    clock_t start_bubble = clock();
    bubble_sort(array, ARRAY_SIZE);
    clock_t end_bubble = clock();
    double time_bubble = ((double) (end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds\n", time_bubble);
    
    // refill array with random ints
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
    
    // time selection sort
    clock_t start_selection = clock();
    selection_sort(array, ARRAY_SIZE);
    clock_t end_selection = clock();
    double time_selection = ((double) (end_selection - start_selection)) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds\n", time_selection);
    
    return 0;
}