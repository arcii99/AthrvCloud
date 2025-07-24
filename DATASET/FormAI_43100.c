//FormAI DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num1 = 5;
    int num2 = 7;

    printf("Factorial of %d: %d\n", num1, factorial(num1));
    printf("Fibonacci Number at index %d: %d\n", num2, fibonacci(num2));

    return 0;
}