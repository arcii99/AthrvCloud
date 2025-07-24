//FormAI DATASET v1.0 Category: Arithmetic ; Style: high level of detail
#include <stdio.h>

int main() {
    int a = 5, b = 7, c;
    float x = 3.5, y = 2.0, z;
    // Addition of integers
    c = a + b;
    printf("Addition of %d and %d is %d\n", a, b, c);
    // Subtraction of integers
    c = a - b;
    printf("Subtraction of %d and %d is %d\n", a, b, c);
    // Division of floats
    z = x / y;
    printf("Division of %f and %f is %f\n", x, y, z);
    // Modulus operator
    c = b % a;
    printf("Modulus of %d and %d is %d\n", b, a, c);
    // Increment operator
    a++;
    printf("Value of a after increment is %d\n", a);
    // Decrement operator
    b--;
    printf("Value of b after decrement is %d\n", b);
    // Multiplication of integers and float
    z = a * y;
    printf("Multiplication of %d and %f is %f\n", a, y, z);
    return 0;
}