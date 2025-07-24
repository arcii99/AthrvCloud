//FormAI DATASET v1.0 Category: Benchmarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50000
#define MAX_NUMBER 10000

int array[ARRAY_SIZE];

double calculate_time(clock_t start, clock_t end) {
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

void fill_array() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % MAX_NUMBER;
    }
}

void print_array() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selection_sort() {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

int main() {
    fill_array();
    clock_t start = clock();
    selection_sort();
    clock_t end = clock();
    printf("Sorted array:\n");
    print_array();
    printf("Time taken: %f seconds\n", calculate_time(start, end));
    return 0;
}