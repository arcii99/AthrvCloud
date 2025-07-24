//FormAI DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num, fact, fib;

    printf("Enter a number: ");
    scanf("%d", &num);

    fact = factorial(num);
    fib = fibonacci(num);

    printf("Factorial of %d is: %d\n", num, fact);
    printf("Fibonacci series up to %d term is: ", num);

    for (int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}