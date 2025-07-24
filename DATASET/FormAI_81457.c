//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: minimalist
#include <stdio.h>

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    printf("Enter number of terms in Fibonacci sequence: ");
    scanf("%d", &n);
    printf("Fibonacci sequence of %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    return 0;
}