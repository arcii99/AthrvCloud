//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

int main() {
    int n, i = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. The number of terms must be positive.\n");
        return 0;
    }

    printf("\nFibonacci sequence:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}