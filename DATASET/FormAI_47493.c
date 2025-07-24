//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 1000000

void initialize_array(int array[], int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        array[i] = rand() % num_elements; // fill array with random values
    }
}

void bubble_sort(int array[], int num_elements) {
    for (int i = 0; i < num_elements - 1; i++) {
        for (int j = 0; j < num_elements - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print_array(int array[], int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[NUM_ELEMENTS];
    initialize_array(array, NUM_ELEMENTS);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bubble_sort(array, NUM_ELEMENTS);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    print_array(array, NUM_ELEMENTS);
    printf("Time taken for bubble sort: %lf seconds\n", cpu_time_used);

    return 0;
}