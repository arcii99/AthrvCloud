//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
// Let's write a program to calculate the Fibonacci sequence using a performance-critical component. Yay!

#include <stdio.h>

long fibonacci(long n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        long prev1 = 0;
        long prev2 = 1;
        long current;
        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
    }
}

int main() {
    // Let's test our performance-critical Fibonacci function! Yay!
    printf("Fibonacci(0) = %ld\n", fibonacci(0));
    printf("Fibonacci(1) = %ld\n", fibonacci(1));
    printf("Fibonacci(2) = %ld\n", fibonacci(2));
    printf("Fibonacci(3) = %ld\n", fibonacci(3));
    printf("Fibonacci(4) = %ld\n", fibonacci(4));
    printf("Fibonacci(5) = %ld\n", fibonacci(5));
    printf("Fibonacci(10) = %ld\n", fibonacci(10));
    printf("Fibonacci(20) = %ld\n", fibonacci(20));
    printf("Fibonacci(30) = %ld\n", fibonacci(30));
    printf("Fibonacci(40) = %ld\n", fibonacci(40));
    printf("Fibonacci(50) = %ld\n", fibonacci(50));
    
    return 0;
}