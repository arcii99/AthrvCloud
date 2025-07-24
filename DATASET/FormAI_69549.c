//FormAI DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void generate_random_array(int *arr) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

int cmpfunc (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

void measure_sort_time(int *arr) {
    clock_t t;
    t = clock();
    qsort(arr, SIZE, sizeof(int), cmpfunc);
    t = clock() - t;
    double time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf(" Time taken by sorting function is %f seconds \n", time_taken);
}

int main() {
    int arr[SIZE];
    generate_random_array(arr);
    measure_sort_time(arr);
    return 0;
}