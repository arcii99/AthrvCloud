//FormAI DATASET v1.0 Category: Benchmarking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_ELEMENTS 1000000

void bubble_sort(long int arr[], int n) {
    int i, j;
    long int temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    // Generate random array of numbers
    long int arr[NUM_OF_ELEMENTS];
    srand(time(NULL));
    for(int i=0; i<NUM_OF_ELEMENTS; i++) {
        arr[i] = rand();
    }

    // Bubble Sort Execution Time
    clock_t begin = clock();
    bubble_sort(arr, NUM_OF_ELEMENTS);
    clock_t end = clock();
    double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Bubble Sort Execution Time: %f seconds\n", time_spent);

    return 0;
}