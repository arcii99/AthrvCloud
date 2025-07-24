//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
#include <stdio.h>

int fibonacci(int n);
void printFibonacciSequence(int n);

int main() {
    int n = 0;
    printf("Please enter the number of terms in the Fibonacci sequence to generate: ");
    scanf("%d", &n);

    printf("The first %d terms in the Fibonacci sequence are:\n", n);
    printFibonacciSequence(n);

    return 0;
}

// Recursive function to calculate the Nth value in the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to print the first n terms in the Fibonacci sequence
void printFibonacciSequence(int n) {
    if (n <= 0) {
        printf("Error: Invalid input. Number of terms must be greater than zero.");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}