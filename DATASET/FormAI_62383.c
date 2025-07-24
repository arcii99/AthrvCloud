//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n, i, j, fib;

    printf("Enter the number of terms in the Fibonacci Sequence: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        fib = fibonacci(i);
        if (fib < 0) {
            printf("%d\n", fib);
            break;
        }
        for (j = 0; j < fib; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}