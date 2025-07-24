//FormAI DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

// Function to initialize the array with random numbers
void init_arr(int arr[]){
    for(int i = 0; i < ARR_SIZE; i++){
        arr[i] = rand();
    }
}

// Function to perform selection sort on the array
void selection_sort(int arr[]){
    int i, j, min_idx, temp;
    for (i = 0; i < ARR_SIZE-1; i++){
        min_idx = i;
        for (j = i+1; j < ARR_SIZE; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform insertion sort on the array
void insertion_sort(int arr[]){
    int i, key, j;
    for (i = 1; i < ARR_SIZE; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(void){
    int arr[ARR_SIZE];
    clock_t start, end;
    double cpu_time_used;

    // Initialize the array with random numbers
    init_arr(arr);

    // Measure the time taken to perform selection sort
    start = clock();
    selection_sort(arr);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to perform selection sort: %f seconds\n", cpu_time_used);

    // Initialize the array with random numbers again
    init_arr(arr);

    // Measure the time taken to perform insertion sort
    start = clock();
    insertion_sort(arr);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to perform insertion sort: %f seconds\n", cpu_time_used);

    return 0;
}