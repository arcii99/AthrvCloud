//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int fibonacci(int n)
{
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main()
{
    int num = 5;
    int fact = factorial(num);

    printf("The factorial of %d is %d\n", num, fact);

    int num1 = 10, num2 = 25;
    int gcdValue = gcd(num1, num2);

    printf("The gcd of %d and %d is %d\n", num1, num2, gcdValue);

    int fibNum = 6;
    int fibValue = fibonacci(fibNum);

    printf("The %dth fibonacci number is %d\n", fibNum, fibValue);

    return 0;
}