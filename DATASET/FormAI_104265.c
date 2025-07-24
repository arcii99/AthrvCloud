//FormAI DATASET v1.0 Category: Scientific ; Style: thoughtful
#include <stdio.h>

// Function to compute the factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to compute the nth term of the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\n");

    printf("Factorial of %d is %d\n\n", n, factorial(n));

    printf("Fibonacci sequence upto %d terms is: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}