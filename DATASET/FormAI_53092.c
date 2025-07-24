//FormAI DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

void printRecursive(int n) {
    if(n == 0) return;
    printf("%d\n", n);
    printRecursive(n-1);
}

int sum(int n) {
    if(n == 0) return 0;
    return n + sum(n-1);
}

int factorial(int n) {
    if(n==0 || n==1) return 1;
    return n * factorial(n-1);
}

int fibonacci(int n) {
    if(n == 0 || n == 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    printf("Printing 5 to 1 recursively:\n");
    printRecursive(5);

    printf("\nSum of first 10 numbers: %d\n", sum(10));

    printf("Factorial of 5: %d\n", factorial(5));

    printf("Fibonacci number at 7th position: %d\n", fibonacci(7));

    return 0;
}