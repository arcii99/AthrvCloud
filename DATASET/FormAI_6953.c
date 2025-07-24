//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubble_sort(int *arr, int len) {
    int temp;
    for(int i=0; i<len-1; i++) {
        for(int j=0; j<len-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int *arr, int len) {
    int min_index;
    int temp;
    for(int i=0; i<len-1; i++) {
        min_index = i;
        for(int j=i+1; j<len; j++) {
            if(arr[j]<arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    clock_t start, end;
    int arr[ARRAY_SIZE];
    int arr_copy[ARRAY_SIZE];

    // Fill array with random numbers
    srand(time(NULL));
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
        arr_copy[i] = arr[i];
    }

    // Bubble sort benchmark
    printf("Bubble Sort:\n");
    start = clock();
    bubble_sort(arr, ARRAY_SIZE);
    end = clock();
    printf("Time taken: %lf seconds\n", ((double)(end-start))/CLOCKS_PER_SEC);

    // Selection sort benchmark
    printf("Selection Sort:\n");
    start = clock();
    selection_sort(arr_copy, ARRAY_SIZE);
    end = clock();
    printf("Time taken: %lf seconds\n", ((double)(end-start))/CLOCKS_PER_SEC);

    return 0;
}