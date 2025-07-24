//FormAI DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>

// define a function to calculate factorial
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

// define a function to calculate squares
int square(int n) {
    return n * n;
}

int main() {
    int a = 5;
    int b = 10;

    printf("Ken Thompson Calculator\n");
    printf("=======================\n\n");

    printf("Addition of %d and %d is: %d\n", a, b, a + b);
    printf("Subtraction of %d from %d is: %d\n", a, b, b - a);
    printf("Division of %d by %d is: %d\n", b, a, b / a);
    printf("Multiplication of %d and %d is: %d\n", a, b, a * b);
    printf("Remainder when %d is divided by %d is: %d\n", b, a, b % a);

    printf("Factorial of %d is: %d\n", a, factorial(a));
    printf("Square of %d is: %d\n", b, square(b));
    printf("Sum of first %d numbers is: %d\n", a, (a * (a + 1)) / 2);

    printf("\nThank you for using Ken Thompson Calculator!\n");
    return 0;
}