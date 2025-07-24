//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void fill_array(int* arr) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

int sum_array(int* arr) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[SIZE];
    
    clock_t start = clock();
    fill_array(arr);
    printf("Time taken to fill array: %f seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    
    start = clock();
    int sum = sum_array(arr);
    printf("Sum of array elements: %d\n", sum);
    printf("Time taken to compute sum: %f seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    
    return 0;
}