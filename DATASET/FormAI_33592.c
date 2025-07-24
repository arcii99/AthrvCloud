//FormAI DATASET v1.0 Category: Recursive ; Style: unmistakable
#include <stdio.h>

int factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    // Recursive case
    else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive case
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial of %d is %d\n", num, factorial(num));
    printf("Fibonacci number at position %d is %d\n", num, fibonacci(num));

    return 0;
}