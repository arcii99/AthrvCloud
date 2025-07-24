//FormAI DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void recursiveSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }
    recursiveSort(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main(void) {
    srand(time(0)); // for random number generation
    int arr[1000];
    int n = 1000;

    // filling array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%1000 + 1;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    recursiveSort(arr, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by Recursive Insertion Sort: %lf seconds\n", cpu_time_used);
    return 0;
}