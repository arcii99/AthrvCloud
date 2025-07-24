//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: recursive
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    else if (b % 2 == 0) {
        int temp = pow(a, b/2);
        return temp * temp;
    }
    else {
        return a * pow(a, b-1);
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}

int main() {
    int n = 5;
    int f = factorial(n);
    printf("Factorial of %d is %d\n", n, f);

    int m = 10;
    int fib = fibonacci(m);
    printf("Fibonacci sequence at position %d is %d\n", m, fib);

    int a = 2, b = 8;
    int g = gcd(a, b);
    printf("GCD of %d and %d is %d\n", a, b, g);

    int x = 3, y = 4;
    int p = pow(x, y);
    printf("%d raised to the power of %d is %d\n", x, y, p);

    return 0;
}