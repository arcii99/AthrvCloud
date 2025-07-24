//FormAI DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

void countDown(int n) {
    if (n == 0) {
        printf("Blast off!\n");
    } else {
        printf("%d\n", n);
        countDown(n-1);
    }
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));
    printf("Counting down from %d:\n", n);
    countDown(n);
    printf("The first %d numbers in the Fibonacci sequence are:\n", n);
    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}