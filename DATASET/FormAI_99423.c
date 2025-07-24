//FormAI DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n = 100000000;
    int *arr = malloc(sizeof(int) * n);
    clock_t start, end;
    double total_cpu_time, time_per_element, time_per_operation;
    
    // Generate random values for the array
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    
    // Benchmarking for loop to iterate through array and sum all the values
    start = clock();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    end = clock();
    
    total_cpu_time = ((double) (end - start) / CLOCKS_PER_SEC);
    time_per_element = total_cpu_time / n;
    time_per_operation = total_cpu_time / (n * 2); // Add and array index access
    
    printf("Time taken to sum %d elements: %f seconds\n", n, total_cpu_time);
    printf("Time per element: %f seconds\n", time_per_element);
    printf("Time per operation (addition and index access): %f seconds\n", time_per_operation);

    free(arr);
    return 0;
}