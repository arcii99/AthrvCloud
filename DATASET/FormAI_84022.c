//FormAI DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <time.h>

#define MAX_ITERATIONS 100000

long fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void run_fibonacci_benchmark() {
    int i;
    clock_t start_time, end_time;
    double elapsed_time;

    printf("Fibonacci Benchmark\n");
    printf("--------------------\n");

    for (i = 0; i <= 40; i += 5) {
        start_time = clock();
        fibonacci(i);
        end_time = clock();

        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Fibonacci(%d) took %f seconds\n", i, elapsed_time);
    }
}

int main() {
    run_fibonacci_benchmark();

    return 0;
}