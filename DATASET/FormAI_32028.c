//FormAI DATASET v1.0 Category: Benchmarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0 ; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n = 10000; // Size of array
    int arr[n];
    
    // Generate array of random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    
    // Record start time
    clock_t t = clock();
    
    // Sort the array
    bubble_sort(arr, n);
    
    // Record end time
    t = clock() - t;
    
    // Calculate elapsed time in seconds
    double elapsed = ((double)t)/CLOCKS_PER_SEC;
    
    printf("Time elapsed: %f seconds\n", elapsed);
    
    return 0;
}