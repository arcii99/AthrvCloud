//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int factorial(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int sum(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + sum(n-1);
    }
}

int main() {
    int n = 10;
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    printf("Factorial(%d) = %d\n", n, factorial(n));
    printf("Sum(%d) = %d\n", n, sum(n));
    return 0;
}