//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define ITERATIONS 100

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void print_array(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int main() {
    int array[ARRAY_SIZE];
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = random_number(0, ARRAY_SIZE);
    }

    printf("Unsorted array:\n");
    print_array(array, ARRAY_SIZE);

    clock_t start_time = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        bubblesort(array, ARRAY_SIZE);
    }
    clock_t end_time = clock();

    double average_time = (double) (end_time - start_time) / CLOCKS_PER_SEC / ITERATIONS;
    printf("Sorted array:\n");
    print_array(array, ARRAY_SIZE);
    printf("Average time taken: %.10f seconds\n", average_time);

    return 0;
}