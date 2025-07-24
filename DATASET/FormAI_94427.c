//FormAI DATASET v1.0 Category: Funny ; Style: mathematical
#include <stdio.h>

int main() {
    int a = 20, b = 10;
    float c = 4.5;

    printf("Let's do some math!\n");

    // Addition
    printf("Addition of %d and %d: %d\n", a, b, a + b);

    // Subtraction
    printf("Subtraction of %d and %d: %d\n", a, b, a - b);

    // Multiplication
    printf("Multiplication of %d and %.1f: %.2f\n", a, c, a * c);

    // Division
    printf("Division of %.1f and %d: %.2f\n", c, b, c / b);

    // Modulus
    printf("Modulo of %d and %d: %d\n", a, b, a % b);

    // Floor division
    printf("Floor Division of %d and %d: %d\n", a, b, a / b);

    // Absolute value
    printf("Absolute value of %d: %d\n", -a, abs(-a));

    // Power
    printf("Squaring %d: %d\n", a, a * a);

    // Increment
    b++;
    printf("Incrementing b: %d\n", b);

    // Decrement
    a--;
    printf("Decrementing a: %d\n", a);

    return 0;
}