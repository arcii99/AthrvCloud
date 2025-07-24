//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: recursive
#include <stdio.h>

// Recursive function to find the n-th term of the Fibonacci series
unsigned int fibonacci(unsigned int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    unsigned int n = 10;  // Example value of n
    
    // Compute and print first n Fibonacci numbers
    printf("First %u Fibonacci numbers:\n", n);
    for (unsigned int i = 0; i < n; i++) {
        printf("%u ", fibonacci(i));
    }
    printf("\n");

    return 0;
}