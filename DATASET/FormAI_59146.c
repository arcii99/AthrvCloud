//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE 1000000
#define RUNS 1000000

int array[ARRAY_SIZE];

void init_array() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
}

void print_array() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* Implementation of bubble sort */
void bubble_sort(int arr[], int size) {
    int temp, i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Utility function to compute time difference */
double timeval_diff(struct timeval *start_time, struct timeval *end_time) {
    return (double)(end_time->tv_sec - start_time->tv_sec)
        + (double)(end_time->tv_usec - start_time->tv_usec) / 1000000;
}

int main() {
    struct timeval start_time, end_time;
    double total_time;
    init_array();

    gettimeofday(&start_time, NULL);
    for (int i = 0; i < RUNS; i++) {
        bubble_sort(array, ARRAY_SIZE);
    }
    gettimeofday(&end_time, NULL);

    total_time = timeval_diff(&start_time, &end_time);
    printf("Execution Time for %d runs of bubble sort with array size %d: %.6f\n",
           RUNS, ARRAY_SIZE, total_time);

    return 0;
}