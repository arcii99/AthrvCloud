//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

/* This is a recursive function that calculates the nth Fibonacci number */
int Fibonacci(int n) {

    if (n == 0 || n == 1)
        return n;

    return (Fibonacci(n-1) + Fibonacci(n-2));
}

int main() {
    int n;
    printf("Enter n to compute the nth Fibonacci number:");
    scanf("%d", &n);

    printf("The %dth Fibonacci number is %d", n, Fibonacci(n));

    return 0;
}