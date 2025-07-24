//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main() {
    clock_t start, end;
    double cpu_time_used;

    int *arr;
    arr = (int *)malloc(MAX * sizeof(int));

    // Generate random values and fill the array
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
    }

    // Measure the time taken to sort the array using Bubble Sort
    start = clock();
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d values using bubble sort: %lf seconds\n", MAX, cpu_time_used);

    free(arr);

    return 0;
}