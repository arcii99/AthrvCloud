//FormAI DATASET v1.0 Category: Recursive ; Style: creative
/*
 * This is a recursive program that demonstrates Fibonacci sequence calculations.
 * It uses recursion to generate the Fibonacci sequence up to the specified number of terms.
 * The program prompts the user to enter the desired number of terms, and then displays the result.
 */

#include <stdio.h>

// Function to calculate the n-th term of the Fibonacci sequence
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &n);
    printf("The first %d terms of the Fibonacci sequence are:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}