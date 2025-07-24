//FormAI DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 1000000;
    }

    start = clock();
    bubble_sort(arr, MAX_SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort of %d elements: %f seconds.\n", MAX_SIZE, cpu_time_used);

    return 0;
}