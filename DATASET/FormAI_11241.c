//FormAI DATASET v1.0 Category: Benchmarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define NUM_TESTS 100000

void initialize_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

void iterative_sum(int *arr, int *result) {
    *result = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        *result += arr[i];
    }
}

void recursive_sum(int *arr, int start_index, int end_index, int *result) {
    if (start_index == end_index) {
        *result = arr[start_index];
    } else {
        int mid_index = (start_index + end_index) / 2;
        int left_sum, right_sum;
        recursive_sum(arr, start_index, mid_index, &left_sum);
        recursive_sum(arr, mid_index + 1, end_index, &right_sum);
        *result = left_sum + right_sum;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    initialize_array(arr);

    clock_t start_time, end_time;
    double iterative_time, recursive_time;

    /* Iterative sum benchmark */
    int iterative_result;
    start_time = clock();
    for (int i = 0; i < NUM_TESTS; i++) {
        iterative_sum(arr, &iterative_result);
    }
    end_time = clock();
    iterative_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    /* Recursive sum benchmark */
    int recursive_result;
    start_time = clock();
    for (int i = 0; i < NUM_TESTS; i++) {
        recursive_sum(arr, 0, ARRAY_SIZE - 1, &recursive_result);
    }
    end_time = clock();
    recursive_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Iterative sum time: %lf seconds\n", iterative_time);
    printf("Recursive sum time: %lf seconds\n", recursive_time);

    return 0;
}