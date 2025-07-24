//FormAI DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>

int main() {
    int a = 5, b = 7, c = 9, d = 11;
    float x = 1.5, y = 2.5, z = 3.5;

    printf("Original values:\n");
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    printf("x = %.2f, y = %.2f, z = %.2f\n\n", x, y, z);

    // Shifting values left
    a <<= 2;
    b <<= 3;
    c <<= 4;
    d <<= 5;

    printf("After left shifting:\n");
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    // Shifting values right
    x -= 0.5;
    y -= 1.0;
    z -= 1.5;

    printf("After subtracting from right shifted values:\n");
    printf("x = %.2f, y = %.2f, z = %.2f\n\n", x, y, z);

    // Adding shifted values
    int sum1 = a + b + c;
    float sum2 = x + y + z;

    printf("Sum of shifted integer values: %d\n", sum1);
    printf("Sum of shifted float values: %.2f\n\n", sum2);

    // Multiplying shifted values
    int product1 = a * b * c * d;
    float product2 = x * y * z;

    printf("Product of shifted integer values: %d\n", product1);
    printf("Product of shifted float values: %.2f\n", product2);

    return 0;
}