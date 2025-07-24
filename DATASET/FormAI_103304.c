//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Ada Lovelace
// Ada Lovelace Style C Program
// This program calculates the factorial of a number using a recursive function

#include <stdio.h>

// Recursive function to calculate the factorial of a number
unsigned long int factorial(unsigned int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    unsigned int num;
    unsigned long int result;
    
    printf("Please enter a non-negative integer: ");
    scanf("%u", &num);
    
    result = factorial(num);
    
    printf("The factorial of %u is %lu\n", num, result);
    
    return 0;
}