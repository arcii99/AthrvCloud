//FormAI DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Fibonacci Series up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    return 0;
}