//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2); // recursion
    }
}

int main() {
    int n, i, j, k;

    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);

    // printing the Fibonacci sequence
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    printf("\nFibonacci sequence visualizer:\n");
    for (i = 0; i < n; i++) {
        k = fibonacci(i);
        for (j = 0; j < k; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}