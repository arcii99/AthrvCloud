//FormAI DATASET v1.0 Category: Arithmetic ; Style: Donald Knuth
#include <stdio.h>

/* Returns the factorial of a given integer using recursion */
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

/* Returns the nth Fibonacci number using recursion */
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

/* Prints a multiplication table from 1 to n */
void multiplication_table(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        printf("%d | ", i);
        for (j = 1; j <= n; j++) {
            printf("%d ", i*j);
        }
        printf("\n");
    }
}

/* Calculates the sum of all the multiples of 3 or 5 under n */
int sum_of_multiples(int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n = 10;

    printf("Factorial of %d: %d\n", n, factorial(n));
    printf("Fibonacci number at index %d: %d\n", n, fibonacci(n));

    printf("Multiplication table:\n");
    multiplication_table(n);

    printf("Sum of multiples of 3 or 5 under %d: %d\n", n, sum_of_multiples(n));

    return 0;
}