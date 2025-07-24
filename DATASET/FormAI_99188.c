//FormAI DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 10000000; // set array size
    int *arr = (int*) malloc(size * sizeof(int)); // allocate memory for array
    
    // populate array with random numbers
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
    
    // calculate time taken for sequential search
    clock_t start = clock();
    int key = rand() % size;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            break;
        }
    }
    clock_t end = clock();
    double time_taken_seq = (double)(end - start) / CLOCKS_PER_SEC;
    
    // calculate time taken for binary search
    start = clock();
    int first = 0, last = size - 1, middle;
    while (first <= last) {
        middle = (first + last) / 2;
        if (arr[middle] == key) {
            break;
        } else if (key < arr[middle]) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    end = clock();
    double time_taken_bin = (double)(end - start) / CLOCKS_PER_SEC;
    
    // output results
    printf("Sequential search took %f seconds\n", time_taken_seq);
    printf("Binary search took %f seconds\n", time_taken_bin);
    
    free(arr); // free memory
    
    return 0;
}