//FormAI DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>

int fibonacci(int n);

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Fibonacci(%d): %d", n, fibonacci(n));
    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int fib0 = 0;
        int fib1 = 1;
        int fibN = 0;
        for (int i = 2; i <= n; i++) {
            fibN = fib0 + fib1;
            fib0 = fib1;
            fib1 = fibN;
        }
        return fibN;
    }
}