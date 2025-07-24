//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

/* function to calculate average time taken */
double calculate_average_time(int (*func)(int *, int), int *arr, int arr_size, int iterations) {
    double total_time = 0;
    clock_t start_time, end_time;
    for (int i = 0; i < iterations; i++) {
        start_time = clock();
        func(arr, arr_size);
        end_time = clock();
        total_time += ((double)(end_time - start_time)) / (CLOCKS_PER_SEC / 1000);
    }
    return total_time / iterations;
}

/* function to square all the elements in an array */
void square_array(int *arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        arr[i] = arr[i] * arr[i];
    }
}

int main() {
    int arr[MAX_NUM];
    for (int i = 0; i < MAX_NUM; i++) {
        arr[i] = i;
    }
    int iterations = 100;

    /* benchmarking square_array function */
    double average_time = calculate_average_time(square_array, arr, MAX_NUM, iterations);
    printf("Average time taken to square all elements in an array of %d integers over %d iterations: %f ms\n", MAX_NUM, iterations, average_time);
    return 0;
}