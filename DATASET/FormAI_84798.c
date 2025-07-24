//FormAI DATASET v1.0 Category: Benchmarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>

#define ARR_SIZE 100000

int main() {
    int arr[ARR_SIZE];
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    // initialize array with random values
    for (i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Starting benchmark...\n");

    // measure time taken by bubble sort algorithm on array
    start = clock();
    for (i = 0; i < ARR_SIZE-1; i++) {
        for (j = 0; j < ARR_SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();

    // calculate CPU time taken and print result
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds to complete.\n", cpu_time_used);

    // measure time taken by insertion sort algorithm on array
    start = clock();
    for (i = 1; i < ARR_SIZE; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    end = clock();

    // calculate CPU time taken and print result
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds to complete.\n", cpu_time_used);

    return 0;
}