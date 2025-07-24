//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n) { 
    int i, j; 
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[1000], i, j, temp;
    clock_t start, end;

    // Initialize array with random integers
    for(i=0; i<1000; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    // Sort the array using bubble sort and time it
    start = clock();
    bubbleSort(arr, 1000);
    end = clock();

    // Calculate the time taken for sorting
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort 1000 integers using bubble sort: %f seconds\n", cpu_time_used);

    return 0;
}