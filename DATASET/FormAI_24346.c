//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr_insertion[ARRAY_SIZE], arr_bubble[ARRAY_SIZE], i;
    clock_t start, end_insertion, end_bubble;

    // fill arrays with random integers
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr_insertion[i] = rand() % ARRAY_SIZE;
        arr_bubble[i] = arr_insertion[i];
    }

    // benchmark insertion sort
    start = clock();
    insertion_sort(arr_insertion, ARRAY_SIZE);
    end_insertion = clock();

    // benchmark bubble sort
    start = clock();
    bubble_sort(arr_bubble, ARRAY_SIZE);
    end_bubble = clock();

    // output results
    printf("Insertion sort took %f seconds\n", ((double)(end_insertion - start)) / CLOCKS_PER_SEC);
    printf("Bubble sort took %f seconds\n", ((double)(end_bubble - start)) / CLOCKS_PER_SEC);

    return 0;
}