//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>

int fibonacciRecursive(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive case
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &n);

    printf("\nGenerating the first %d terms of the Fibonacci sequence:\n", n);
    printf("0 ");

    for (int i = 1; i < n; i++) {
        int term = fibonacciRecursive(i);
        printf("%d ", term);
    }

    return 0;
}