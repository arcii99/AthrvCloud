//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>

int fibonacci(int n);

int main() {
    int n;

    printf("Enter the number of terms you want to see in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nFibonacci sequence for %d terms:\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}