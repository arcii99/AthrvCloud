//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

/* Function to generate random integer array */
void generate_random_array(int *array, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }
}

/* Function to bubble sort an array of integers */
void bubble_sort(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/* Function to benchmark bubble sort algorithm */
void benchmark_bubble_sort() {
    int array[ARRAY_SIZE];
    generate_random_array(array, ARRAY_SIZE);

    clock_t start_time = clock();
    bubble_sort(array, ARRAY_SIZE);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time for bubble sort on array of size %d: %lf seconds\n", ARRAY_SIZE, elapsed_time);
}

/* Function to quicksort an array of integers */
void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

/* Function to benchmark quicksort algorithm */
void benchmark_quick_sort() {
    int array[ARRAY_SIZE];
    generate_random_array(array, ARRAY_SIZE);

    clock_t start_time = clock();
    quick_sort(array, 0, ARRAY_SIZE - 1);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time for quicksort on array of size %d: %lf seconds\n", ARRAY_SIZE, elapsed_time);
}

/* Main function */
int main() {
    benchmark_bubble_sort();
    benchmark_quick_sort();

    return 0;
}