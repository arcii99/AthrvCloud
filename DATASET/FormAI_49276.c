//FormAI DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NSIZE 1000000

double calculate_time(clock_t start, clock_t end) {
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

void bubble_sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, arr[NSIZE];
    clock_t start, end;
    double exec_time;

    srand(time(NULL));

    // initialize array with random numbers
    for (i = 0; i < NSIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // benchmark bubble sort
    start = clock();
    bubble_sort(arr, NSIZE);
    end = clock();
    exec_time = calculate_time(start, end);
    printf("Bubble sort execution time: %f seconds.\n", exec_time);

    return 0;
}