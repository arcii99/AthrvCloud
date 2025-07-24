//FormAI DATASET v1.0 Category: Benchmarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[1000000], n = 1000000, i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    // Fill unsorted array with random integers
    for (i = 0; i < n; i++){
        arr[i] = rand() % 10000 + 1;
    }

    // Bubble sort for unsorted array
    start = clock();
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort in unsorted array: %f seconds\n", cpu_time_used);

    // Bubble sort for sorted array
    start = clock();
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort in sorted array: %f seconds\n", cpu_time_used);

    return 0;
}