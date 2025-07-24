//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int arr[SIZE];
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;
    
    // Initialize the array with random values between 0 and 99
    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    // Bubble Sort Algorithm
    start = clock();
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted Array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    printf("Time taken by Bubble Sort Algorithm: %f seconds\n", cpu_time_used);
    
    return 0;
}