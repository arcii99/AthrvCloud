//FormAI DATASET v1.0 Category: Benchmarking ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

/* Generate an array of random integers */
void generate_array(int array[]) {
    srand(time(NULL)); // Seed random generator
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100 + 1; // Random integer between 1 and 100
    }
}

/* Bubble sort algorithm */
void bubble_sort(int array[]) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/* Quick sort algorithm */
void quick_sort(int array[], int left, int right) {
    if (left < right) {
        int pivot = array[(left + right) / 2];
        int i = left - 1;
        int j = right + 1;
        while (1) {
            while (array[++i] < pivot);
            while (array[--j] > pivot);
            if (i >= j) break;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        quick_sort(array, left, i - 1);
        quick_sort(array, j + 1, right);
    }
}

/* Main function */
int main() {
    int array[ARRAY_SIZE];

    /* Generate array */
    generate_array(array);

    /* Benchmark Bubble Sort */
    clock_t start = clock();
    bubble_sort(array);
    clock_t end = clock();
    float bubble_sort_time = ((float) (end - start)) / CLOCKS_PER_SEC;

    /* Generate array again for Quick Sort */
    generate_array(array);

    /* Benchmark Quick Sort */
    start = clock();
    quick_sort(array, 0, ARRAY_SIZE - 1);
    end = clock();
    float quick_sort_time = ((float) (end - start)) / CLOCKS_PER_SEC;

    /* Print results */
    printf("Bubble Sort Time: %f seconds\n", bubble_sort_time);
    printf("Quick Sort Time: %f seconds\n", quick_sort_time);

    return 0;
}