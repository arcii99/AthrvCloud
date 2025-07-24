//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Generate random data to fill the array
void generate_data(int *array) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
}

// Perform quicksort on the array
void quicksort(int *array, int left, int right) {
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2];
    int temp;

    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quicksort(array, left, j);
    }
    if (i < right) {
        quicksort(array, i, right);
    }
}

int main() {
    int data[ARRAY_SIZE];
    clock_t start, end;

    generate_data(data);

    start = clock();
    quicksort(data, 0, ARRAY_SIZE - 1);
    end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}