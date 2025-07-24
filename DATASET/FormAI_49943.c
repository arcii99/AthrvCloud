//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 10000000

void bubble_sort(int array[], int size) {
    int temp;
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void quick_sort(int array[], int low, int high) {
    if (low >= high) return;
    int i = low, j = high, temp;
    int pivot = array[(i+j)/2];
    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(array, low, j);
    quick_sort(array, i, high);
}

int main() {
    int array1[ARRAY_SIZE], array2[ARRAY_SIZE];
    clock_t start, end;
    double time_taken;

    // Generating random numbers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array1[i] = rand() % ARRAY_SIZE;
        array2[i] = array1[i];
    }

    // Bubble sort
    start = clock();
    bubble_sort(array1, ARRAY_SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %.7f seconds\n", time_taken);

    // Quick sort
    start = clock();
    quick_sort(array2, 0, ARRAY_SIZE-1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick sort took %.7f seconds\n", time_taken);

    return 0;
}