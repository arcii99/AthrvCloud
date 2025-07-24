//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
/* Statistical Recursive Program - Fibonacci sequence of a given number */

#include <stdio.h>
#include <stdlib.h>

// Function to recursively calculate the nth Fibonacci number
int fib(int n) {
    // Base case: if n is 0 or 1, return n
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive case: calculate the sum of the (n-1)th and (n-2)th Fibonacci numbers
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    // Declare variables
    int n, i;
    long unsigned int result;

    // Prompt user for input
    printf("Enter a number to find the nth Fibonacci number: ");
    scanf("%d", &n);

    // Call the fib function and store the result
    result = fib(n);

    // Print the result
    printf("The %dth Fibonacci number is %lu\n", n, result);

    return 0;
}