//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
/* This program computes the nth fibonacci number using dynamic programming */
#include <stdio.h>

long long fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%lld\n", fib(n));
    return 0;
}