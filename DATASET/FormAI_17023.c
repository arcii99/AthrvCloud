//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate factorial 
unsigned long long int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

// Function to calculate Fibonacci series 
unsigned long long int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int n = 30; // Input value for factorial and Fibonacci series

    // Benchmarking for factorial function
    start = clock();
    factorial(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for factorial function: %lf seconds\n", cpu_time_used);

    // Benchmarking for Fibonacci series function
    start = clock();
    fibonacci(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Fibonacci series function: %lf seconds\n", cpu_time_used);

    return 0;
}