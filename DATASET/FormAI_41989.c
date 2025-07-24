//FormAI DATASET v1.0 Category: Benchmarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

// function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    int sqrt_num = (int) sqrt(num);
    for (int i = 3; i <= sqrt_num; i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

// function to benchmark different prime number algorithms
void benchmark(int max_num) {
    clock_t start_time, end_time;
    double brute_force_time, optimized_time;

    // brute force method
    start_time = clock();

    int count = 0;
    for (int i = 2; i <= max_num; i++) {
        if (is_prime(i)) count++;
    }

    end_time = clock();
    brute_force_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // optimized method
    start_time = clock();

    count = 0;
    bool *prime = (bool *) calloc(max_num + 1, sizeof(bool));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= max_num; i++) {
        if (!prime[i]) {
            count++;

            for (int j = 2; i * j <= max_num; j++) {
                prime[i*j] = true;
            }
        }
    }

    free(prime);

    end_time = clock();
    optimized_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // print results
    printf("Results for max number %d:\n", max_num);
    printf("Brute force time: %.6fs\n", brute_force_time);
    printf("Optimized time: %.6fs\n", optimized_time);
}

int main() {
    benchmark(1000);
    benchmark(10000);
    benchmark(100000);
    benchmark(1000000);

    return 0;
}