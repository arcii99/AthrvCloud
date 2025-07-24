//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <time.h>

int fibonacci(int n);

int main() {
    clock_t t_start, t_end;
    double cpu_time_used;
    
    int n = 40, fib;
    
    t_start = clock(); // start the clock
    
    fib = fibonacci(n); // function call
    
    t_end = clock(); // end the clock
    
    cpu_time_used = ((double) (t_end - t_start)) / CLOCKS_PER_SEC; // calculate CPU time
    
    printf("The %dth Fibonacci number is %d\n", n, fib);
    printf("CPU Time Used: %f seconds\n", cpu_time_used);

    return 0;
}

int fibonacci(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive call
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}