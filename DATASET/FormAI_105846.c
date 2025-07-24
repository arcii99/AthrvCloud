//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000      // size of our test array

// bubble sort algorithm
void bubble_sort(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// selection sort algorithm
void selection_sort(int array[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
}

// insertion sort algorithm
void insertion_sort(int array[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i-1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

int main() {
    int i, array[ARRAY_SIZE];
    clock_t start, end;     // variables to store start and end time

    // seed random number generator
    srand(time(NULL));

    // fill array with random numbers between 1 and 10000
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10000 + 1;
    }

    // test bubble sort algorithm
    start = clock();
    bubble_sort(array, ARRAY_SIZE);
    end = clock();
    printf("Bubble Sort Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // fill array with new random numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10000 + 1;
    }

    // test selection sort algorithm
    start = clock();
    selection_sort(array, ARRAY_SIZE);
    end = clock();
    printf("Selection Sort Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // fill array with new random numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10000 + 1;
    }

    // test insertion sort algorithm
    start = clock();
    insertion_sort(array, ARRAY_SIZE);
    end = clock();
    printf("Insertion Sort Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}