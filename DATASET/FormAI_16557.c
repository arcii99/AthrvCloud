//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void selection_sort(int arr[]) {
    int i, j, temp;
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertion_sort(int arr[]) {
    int i, j, key;
    for (i = 1; i < N; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int i, arr[N];
    clock_t start, end;
    double cpu_time_used;

    // Initialize array with random integers
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        arr[i] = rand() % (N * 10);
    }

    // Measure time for selection sort
    start = clock();
    selection_sort(arr);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Time: %lf\n", cpu_time_used);

    // Measure time for insertion sort
    start = clock();
    insertion_sort(arr);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %lf\n", cpu_time_used);

    return 0;
}