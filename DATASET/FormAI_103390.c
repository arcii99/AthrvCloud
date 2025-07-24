//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the number of elements in the array
#define N 100000

int main() {
    // declare variables
    clock_t start, end;
    double total_time;
    int i;
    int a[N];

    // initialize the array with random numbers
    for (i = 0; i < N; i++) {
       a[i] = rand() % 100;
    }

    // using bubble sort to sort the array
    start = clock();

    for (i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;

    // print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    // print the time taken to sort the array
    printf("\n\nTime taken: %f seconds\n", total_time);

    return 0;
}