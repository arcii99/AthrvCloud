//FormAI DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int knights[100];
    int n = sizeof(knights) / sizeof(knights[0]);
    
    // Populate knights array with random numbers
    for (int i = 0; i < n; i++) {
        knights[i] = rand() % 101;
    }
    
    // Sort knights array in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (knights[j] > knights[j+1]) {
                int temp = knights[j];
                knights[j] = knights[j+1];
                knights[j+1] = temp;
            }
        }
    }
    
    // Print sorted knights array
    printf("The sorted knights array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", knights[i]);
    }
    
    // Benchmark the sorting algorithm
    clock_t start_time = clock();
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (knights[j] > knights[j+1]) {
                int temp = knights[j];
                knights[j] = knights[j+1];
                knights[j+1] = temp;
            }
        }
    }
    clock_t end_time = clock();
    double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTime elapsed to sort knights array 100,000 times: %f seconds", time_elapsed);
    
    return 0;
}