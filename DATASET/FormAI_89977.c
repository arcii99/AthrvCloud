//FormAI DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>

// Calculate the factorial of a number using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

// Calculate a number raised to the power of another number using recursion
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else if (exponent % 2 == 0) {
        int temp = power(base, exponent/2);
        return temp * temp;
    }
    else {
        return base * power(base, exponent - 1);
    }
}

// Calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Factorial of %d = %d\n", num, factorial(num));
    printf("2 raised to the power of %d = %d\n", num, power(2, num));
    printf("The %dth Fibonacci number = %d\n", num, fibonacci(num));

    return 0;
}