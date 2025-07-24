//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE 1000000

/*
 * This program creates two arrays of size ARRAY_SIZE,
 * fills them with random integers, and then multiplies
 * each element of one array by the corresponding element
 * of the other array. This operation is performed multiple
 * times and the average time taken is calculated.
 */

// Function to fill array with random integers
void fill_array(int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = rand()%1000;
    }
}

// Function to perform element-wise multiplication of two arrays
void multiply_arrays(int *arr1, int *arr2, int size){
    for(int i = 0; i < size; i++){
        arr1[i] = arr1[i] * arr2[i];
    }
}

int main(){
    // Declare and initialize arrays
    int arr1[ARRAY_SIZE];
    int arr2[ARRAY_SIZE];

    // Fill arrays with random integers
    fill_array(arr1, ARRAY_SIZE);
    fill_array(arr2, ARRAY_SIZE);

    // Declare and initialize variables for timing the operation
    struct timeval start_time, end_time;
    long long time_taken = 0;
    int num_runs = 100;

    // Perform the operation multiple times and calculate the average time taken
    for(int i = 0; i < num_runs; i++){
        gettimeofday(&start_time, NULL);
        multiply_arrays(arr1, arr2, ARRAY_SIZE);
        gettimeofday(&end_time, NULL);
        time_taken += (end_time.tv_sec - start_time.tv_sec)*1000000ll + (end_time.tv_usec - start_time.tv_usec);
    }
    time_taken /= num_runs;

    printf("Average time taken for element-wise multiplication of two arrays of size %d: %lld microseconds\n", ARRAY_SIZE, time_taken);

    return 0;
}