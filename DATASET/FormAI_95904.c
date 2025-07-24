//FormAI DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <time.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {

    clock_t start, end;
    double cpu_time_used;

    // Benchmarking the factorial function
    start = clock();
    int fact = factorial(15);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Factorial of 15 is %d\n", fact);
    printf("Time taken to calculate factorial: %f seconds\n", cpu_time_used);

    // Benchmarking the Fibonacci function
    start = clock();
    int fib = fibonacci(30);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("30th Fibonacci number is %d\n", fib);
    printf("Time taken to calculate Fibonacci number: %f seconds\n", cpu_time_used);

    return 0;
}