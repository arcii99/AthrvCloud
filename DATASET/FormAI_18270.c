//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Main function
int main() {
    int n;
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &n);
    printf("\n");

    // Print the Fibonacci sequence
    int i, j, sum;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            sum = fibonacci(j);
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}