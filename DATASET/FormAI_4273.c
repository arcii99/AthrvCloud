//FormAI DATASET v1.0 Category: Benchmarking ; Style: Claude Shannon
#include <stdio.h>
#include <time.h>

double my_function(int n) {
    // A sample function that we want to measure execution time of
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += i * i;
    }
    return result;
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    int n = 10000;
    int iterations = 3;
    
    printf("Measuring the execution time of my_function(%d)\n", n);
    for (int i = 0; i < iterations; i++) {
        start = clock();
        double result = my_function(n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Iteration %d: Result = %lf , Execution time = %lf seconds\n", i+1, result, cpu_time_used);
    }
    
    return 0;
}