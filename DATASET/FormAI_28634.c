//FormAI DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* The main goal of this program is to measure the time it takes to sort an array of
 * integers of length N using bubble sort.
 *
 * Donald Knuth said that "premature optimization is the root of all evil."
 * So, we will start with a naive bubble sort implementation and gradually optimize it.
 */

void naive_bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void improved_bubble_sort(int *arr, int n) {
    int i, j, temp;
    int swapped;          // Flag to indicate whether a swap has occurred
    for (i = 0; i < n; i++) {
        swapped = 0;
        for (j = 0; j < n-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;   // If no swaps occurred, the array is sorted
    }
}

int main() {

    srand(time(0));
    int N = 10000;
    int arr[N];

    // Fill the array with random integers from 1 to 100
    printf("Filling the array with random integers from 1 to 100...\n");
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1;
    }

    printf("Sorting the array using naive bubble sort...\n");
    clock_t start_time = clock();
    naive_bubble_sort(arr, N);
    clock_t end_time = clock();
    printf("Time taken: %f seconds\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);

    printf("Sorting the array using improved bubble sort...\n");
    start_time = clock();
    improved_bubble_sort(arr, N);
    end_time = clock();
    printf("Time taken: %f seconds\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);

    return 0;
}