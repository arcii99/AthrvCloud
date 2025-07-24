//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int i, arr[MAX_NUM];
    clock_t start, end;
    double cpu_time_used;
    
    // Fill the array with random numbers
    srand(time(NULL));
    for (i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % 1000;
    }
    
    // Perform bubble sort and time how long it takes
    start = clock();
    bubble_sort(arr, MAX_NUM);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds\n", cpu_time_used);
    
    // Perform insertion sort and time how long it takes
    srand(time(NULL));
    for (i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % 1000;
    }
    start = clock();
    insertion_sort(arr, MAX_NUM);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort took %f seconds\n", cpu_time_used);
    
    // Perform selection sort and time how long it takes
    srand(time(NULL));
    for (i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % 1000;
    }
    start = clock();
    selection_sort(arr, MAX_NUM);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort took %f seconds\n", cpu_time_used);
    
    return 0;
}