//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n) {
    int fib[n];

    // Assigning initial values for first two numbers in series
    fib[0] = 0; 
    fib[1] = 1;

    // Generating the fibonacci sequence
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Printing out the generated sequence
    printf("The Fibonacci sequence with %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Creating visualization for the sequence
    printf("\nFibonacci Sequence Visually:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Prompting user to enter number of fibonacci numbers to generate
    printf("Enter the number of fibonacci numbers to generate: ");
    scanf("%d", &n);

    // Generating and visualizing the fibonacci sequence
    fibonacci(n);

    return 0;
}