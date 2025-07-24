//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>

// Recursive function to calculate the nth term of Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) { // Base case
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2); // Recursive case
    }
}

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n <= 1) { // Base case
        return 1;
    } else {
        return n * factorial(n-1); // Recursive case
    }
}

// Main function to demonstrate the recursive functions
int main() {
    int n;

    // Fibonacci sequence
    printf("Enter a number to find its nth term in Fibonacci sequence: ");
    scanf("%d", &n);
    printf("%dth term in Fibonacci sequence is %d\n", n, fibonacci(n));

    // Factorial
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));

    return 0;
}