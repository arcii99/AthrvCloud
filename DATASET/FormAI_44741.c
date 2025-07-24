//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
/* This program demonstrates the use of arithmetic operators in C. */
#include <stdio.h>

int main() {
    int a = 10;
    int b = 4;
    int c = 1;
    int result;

    // Addition
    result = a + b;
    printf("%d + %d = %d\n", a, b, result);

    // Subtraction
    result = a - b;
    printf("%d - %d = %d\n", a, b, result);

    // Multiplication
    result = a * b;
    printf("%d * %d = %d\n", a, b, result);

    // Division
    result = a / b;
    printf("%d / %d = %d\n", a, b, result);

    // Modulo
    result = a % b;
    printf("%d %% %d = %d\n", a, b, result);

    // Precedence
    result = a + b * c;
    printf("%d + %d * %d = %d\n", a, b, c, result);

    // Increment
    result = ++a;
    printf("++%d = %d\n", a, result);

    // Decrement
    result = --a;
    printf("--%d = %d\n", a, result);

    return 0;
}