//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;

    // Prompt user for input
    printf("Enter the number of terms in the Fibonacci sequence to generate: ");
    scanf("%d", &n);

    // Check for invalid input
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Print the Fibonacci sequence
    printf("The Fibonacci sequence of %d terms is:\n", n);
    for (int i = 0; i < n; i++) {
        int fib = fibonacci(i);
        printf("%d ", fib);
    }
    printf("\n");

    return 0;
}