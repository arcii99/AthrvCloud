//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 10000000

double computeArraySum(int arr[], int size) {
    double sum = 0.0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i * 2;
    }
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    double result = computeArraySum(arr, ARRAY_SIZE);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The sum of the array is: %f\n", result);
    printf("CPU time used: %f\n", cpu_time_used);
    
    return 0;
}