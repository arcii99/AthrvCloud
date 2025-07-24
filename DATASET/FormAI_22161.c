//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>

int fibonacciSeries(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive case
    else {
        return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
    }
}

void retroFibonacci(int n) {
    // Print header
    printf("Fibonacci series up to %d:\n", n);
    printf("0  1  ");
    // Print series
    for (int i = 2; i <= n; i++) {
        printf("%d  ", fibonacciSeries(i));
    }
    // Print footer
    printf("\n\n");
}

int main() {
    int n = 10;
    retroFibonacci(n);
    return 0;
}