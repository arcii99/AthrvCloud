//FormAI DATASET v1.0 Category: Recursive ; Style: brave
/*
 * A brave recursive program to print the Fibonacci series up to a certain term
 * without using arrays.
 */

#include <stdio.h>

int fibonacci(int n);

int main() {
    int n, i;

    printf("How many terms of the Fibonacci series do you want to see? ");
    scanf("%d", &n);

    printf("The first %d terms of the Fibonacci series are: ", n);

    for (i = 0; i < n; i++) {
        printf("%d, ", fibonacci(i));
    }

    return 0;
}

int fibonacci(int n) {
    if (n == 0) { // Base case: 0th term is 0
        return 0;
    } else if (n == 1) { // Base case: 1st term is 1
        return 1;
    } else { // Recursive case: add the previous two terms
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}