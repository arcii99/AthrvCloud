//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdint.h>

#define MAX_N 100

uint64_t memo[MAX_N];

uint64_t fib(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != 0) {
        return memo[n];
    }
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main() {
    int n;
    printf("Enter a positive integer (<= %d): ", MAX_N);
    scanf("%d", &n);
    if (n < 0 || n > MAX_N) {
        printf("Invalid input\n");
        return 1;
    }
    printf("Fibonacci(%d) = %llu\n", n, fib(n));
    return 0;
}