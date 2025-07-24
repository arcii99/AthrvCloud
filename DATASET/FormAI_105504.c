//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of Fibonacci terms to generate
#define MAX_TERMS 20

// Function to calculate Fibonacci sequence terms recursively
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to print Fibonacci terms visually
void printFibonacci(int n) {
    int i, j, term;
    for (i = 0; i < n; i++) {
        term = fibonacci(i);
        for (j = 0; j < term; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Main function
int main() {
    printf("Fibonacci Sequence Visualizer\n\n");
    printf("Generating the first %d terms of the Fibonacci sequence:\n\n", MAX_TERMS);
    printFibonacci(MAX_TERMS);
    return 0;
}