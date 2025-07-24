//FormAI DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int power(int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        int tmp = power(x, n / 2);
        return tmp * tmp;
    } else {
        return x * power(x, n - 1);
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n = 6;
    printf("Factorial of %d is %d\n", n, factorial(n));
    
    n = 9;
    printf("Fibonacci of %d is %d\n", n, fibonacci(n));
    
    int x = 2, p = 4;
    printf("%d raised to the power of %d is %d\n", x, p, power(x, p));
    
    int a = 24, b = 16;
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    
    return 0;
}