//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random number generator
    const int size = 1000000;
    int arr[size]; // declare array of size 1 million
    int i, j, temp;
    clock_t start, end; // variables to measure execution time
    float time_taken;

    // fill array with random numbers between 1 and 1000
    for(i = 0; i < size; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    // print unsorted array
    printf("Unsorted array: \n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // perform bubble sort and measure execution time
    start = clock();
    for(i = 0; i < size-1; i++) {
        for(j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    time_taken = (float)(end - start) / CLOCKS_PER_SEC;

    // print sorted array and execution time
    printf("\n\nSorted array: \n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nExecution time: %f seconds", time_taken);

    return 0;
}