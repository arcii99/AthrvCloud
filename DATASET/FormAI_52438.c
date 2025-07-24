//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int array[SIZE];
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL)); // Seed rand with current time

    // Populate array with random values between 0 and 99999
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100000;
    }

    // Benchmark sorting time using bubble sort
    start = clock();

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort: %f seconds\n", cpu_time_used);

    // Benchmark sorting time using quick sort
    start = clock();

    quick_sort(array, 0, SIZE - 1);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for quick sort: %f seconds\n", cpu_time_used);

    return 0;
}

void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int partition_index = partition(array, low, high);
        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}