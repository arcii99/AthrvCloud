//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

int pow(int base, int exp) { // recursive power function
    if (exp == 0) {
        return 1;
    } else {
        return base * pow(base, exp - 1);
    }
}

int factorial(int n) { // recursive factorial function
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int fibonacci(int n) { // recursive fibonacci function
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int base = 2;
    int exp = 10;
    int n = 7;

    printf("%d to the power of %d is %d\n", base, exp, pow(base, exp));
    printf("%d! is %d\n", n, factorial(n));
    printf("The 10th number in the fibonacci sequence is %d\n", fibonacci(10));

    return 0;
}