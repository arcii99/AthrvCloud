//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include<stdio.h>
#include<time.h>

#define MAX_NUM 1000000

double run_benchmark() {
    int i, j;
    int is_prime;
    double elapsed_time;
    clock_t start, end;

    start = clock();
    for (i = 2; i <= MAX_NUM; i++) {
        is_prime = 1;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
    }
    end = clock();

    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    return elapsed_time;
}

int main() {
    double elapsed_time;
    int num_benchmarks = 10;
    int i;

    printf("Running %d benchmarks...\n", num_benchmarks);
    for (i = 1; i <= num_benchmarks; i++) {
        elapsed_time = run_benchmark();
        printf("Benchmark %d: Elapsed Time = %lf seconds\n", i, elapsed_time);
    }

    return 0;
}