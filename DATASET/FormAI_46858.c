//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int array[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

int main() {
    int n = 10000;
    int array[n];
    int i;
    clock_t start, end;
    double bubble_sort_time, selection_sort_time;

    // Generate a random array
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        array[i] = rand() % n;
    }

    // Benchmark bubble sort
    start = clock();
    bubble_sort(array, n);
    end = clock();
    bubble_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Benchmark selection sort
    start = clock();
    selection_sort(array, n);
    end = clock();
    selection_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Output results
    printf("Bubble sort time: %f seconds\n", bubble_sort_time);
    printf("Selection sort time: %f seconds\n", selection_sort_time);

    return 0;
}