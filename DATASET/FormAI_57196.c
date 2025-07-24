//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a random array of integers and sorts them in ascending order using the bubble sort algorithm. The performance of the sorting algorithm is critical for the overall efficiency of the program since it is used in a time-critical application. The implementation uses pointers for efficiency. */

#define ARRAY_SIZE 10000

void bubble_sort(int *arr, int size) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i+1]) {
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }
    clock_t start = clock();
    bubble_sort(&arr[0], ARRAY_SIZE);
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted %d integers in %f seconds.\n", ARRAY_SIZE, elapsed_time);
    return 0;
}