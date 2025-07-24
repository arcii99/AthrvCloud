//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: genious
/* A simple program to demonstrate a Performance-Critical Component */
#include <stdio.h>

// Function to calculate the nth Fibonacci number recursively
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    int n = 45;
    int result = fib(n); // Calculate the 45th Fibonacci number
    printf("The %dth Fibonacci number is: %d\n", n, result);
    return 0;
}