//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: minimalist
#include <stdio.h>

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main() {
    int n, i;

    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nFibonacci sequence:\n");

    // Loop to print the Fibonacci sequence
    for(i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}