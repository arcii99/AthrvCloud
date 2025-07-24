//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include <stdio.h>

// Function to print the Fibonacci sequence up to n terms
void fibonacci(int n) {
    int previous = 0, current = 1, next;

    // Starting the sequence from 0, 1
    printf("%d %d ", previous, current);

    // Generating the Fibonacci sequence up to n terms
    for (int i = 2; i < n; i++) {
        next = previous + current;
        printf("%d ", next);
        previous = current;
        current = next;
    }
}

// Function to visualize the Fibonacci sequence
void fibonacciVisualizer(int n) {
    int previous = 0, current = 1, next;

    // Starting the sequence from 0, 1
    printf("%2d %2d ", previous, current);

    // Generating the Fibonacci sequence up to n terms
    for (int i = 2; i < n; i++) {
        next = previous + current;

        // Printing each term with asterisks to visualize the sequence
        for (int j = 0; j < next; j++) {
            printf("*");
        }
        printf(" %2d\n", next);

        previous = current;
        current = next;
    }
}

// Main function to test the Fibonacci sequence visualizer
int main() {
    int n = 10; // Number of terms in the sequence

    printf("Fibonacci sequence up to %d terms:\n", n);
    fibonacci(n);

    printf("\n\nFibonacci sequence visualizer up to %d terms:\n", n);
    fibonacciVisualizer(n);

    return 0;
}