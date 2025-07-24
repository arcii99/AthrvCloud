//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>

// Function to recursively find and print the fibonacci sequence
void fibonacci(int n) {
    // Base case
    if (n <= 1) {
        printf("%d ", n);
        return;
    }

    // Recursive case
    fibonacci(n-1);
    fibonacci(n-2);
}

int main() {
    int n;

    // Prompt user for input
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Call fibonacci function and print sequence
    printf("\nFibonacci Sequence: ");
    fibonacci(n);

    return 0;
}