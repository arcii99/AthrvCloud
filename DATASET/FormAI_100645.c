//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdio.h>
#include <time.h>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n = 40;
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int result = fib(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Result: %d\n", result);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}