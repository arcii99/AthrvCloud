//FormAI DATASET v1.0 Category: Benchmarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void populate_array(int* array, int size);
void bubble_sort(int* array, int size);
void print_array(int* array, int size);

int main() {
    int array[ARRAY_SIZE];
    populate_array(array, ARRAY_SIZE);
    
    clock_t start, end;
    double cpu_time_used;

    /* Measure start time */
    start = clock();
    
    bubble_sort(array, ARRAY_SIZE);

    /* Measure end time */
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted array:\n");
    print_array(array, ARRAY_SIZE);

    printf("Bubble sort took %f seconds to execute.\n", cpu_time_used);
    return 0;
}

void populate_array(int* array, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
}

void bubble_sort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}