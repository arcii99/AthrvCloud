//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: curious
#include <stdio.h>

// This program is a curious implementation of a performance-critical component that
// computes the sum of all even numbers between 1 and the input number using bitwise operators.
// The goal is to achieve maximum performance by using bitwise operations instead of
// traditional arithmetic operations.

int main() {
    int n, sum;
    printf("Enter a number: ");
    scanf("%d", &n);

    sum = ((n & 1) ? n-1 : n) >> 1;

    for (int i = 2; i <= n; i <<= 1) {
        sum += ((n & i) ? i : 0) - ((n & (i-1)) ? i-1 : 0);
    }

    printf("The sum of all even numbers between 1 and %d is %d\n", n, sum);

    return 0;
}