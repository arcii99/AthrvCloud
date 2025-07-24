//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate the average of an array of integers
double calc_avg(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

int main() {
    // initialize variables and arrays
    int arr_size = 1000000;
    int *arr1 = malloc(arr_size * sizeof(int));
    int *arr2 = malloc(arr_size * sizeof(int));

    // populate the arrays with random integers between 1 and 100
    srand(time(NULL));
    for (int i = 0; i < arr_size; i++) {
        arr1[i] = rand() % 100 + 1;
        arr2[i] = rand() % 100 + 1;
    }
    
    // call the calc_avg function and time the execution
    clock_t start_time = clock();
    double avg1 = calc_avg(arr1, arr_size);
    double avg2 = calc_avg(arr2, arr_size);
    double avg_diff = avg1 - avg2;
    clock_t end_time = clock();
    double time_elapsed = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // print the results
    printf("Array size: %d\n", arr_size);
    printf("Avg 1: %f\nAvg 2: %f\nDifference in avgs: %f\n", avg1, avg2, avg_diff);
    printf("Time elapsed: %f seconds\n", time_elapsed);

    // free the allocated memory
    free(arr1);
    free(arr2);

    return 0;
}