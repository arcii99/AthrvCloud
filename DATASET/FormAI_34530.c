//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>

// Recursive function to print fibonacci sequence up to n
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to generate and print fibonacci sequence up to n
void fibonacciSequence(int n) {
    printf("Fibonacci sequence up to %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Main function to execute the program
int main() {
    int n;
    printf("Enter the number of terms in fibonacci sequence to generate: ");
    scanf("%d", &n);
    fibonacciSequence(n);
    return 0;
}