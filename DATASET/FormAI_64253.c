//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: lively
#include <stdio.h>

/**
 * A simple program that calculates the factorial of a number.
 * This program is performance-critical, therefore, performance optimizations are applied.
 */

unsigned long factorial(unsigned int n) {
    unsigned long result = 1;
    
    // No need to compute factorial for 0 and 1
    if (n == 0 || n == 1) {
        return result;
    }
    
    // Precompute factorial for numbers that are less than or equal to 12
    // and avoid unnecessary calculation for larger numbers
    if (n <= 12) {
        for (unsigned int i = 2; i <= n; i++) {
            result *= i;
        }
        
        return result;
    }
    
    // Recursively compute factorial for numbers that are greater than 12
    result = factorial(n - 1) * n;
    return result;
}

int main() {
    unsigned int n;
    
    printf("Enter a non-negative integer to compute its factorial: ");
    scanf("%u", &n);
    
    printf("Factorial of %u is %lu\n", n, factorial(n));
    
    return 0;
}