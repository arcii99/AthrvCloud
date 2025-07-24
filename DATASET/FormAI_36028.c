//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

/* This program demonstrates the usage of bitwise operations in C */

int main() {
    // Declare variables
    int a = 10, b = 25, c;

    // Bitwise AND
    c = a & b;
    printf("a & b = %d\n", c); // Output: 8

    // Bitwise OR
    c = a | b;
    printf("a | b = %d\n", c); // Output: 27

    // Bitwise XOR
    c = a ^ b;
    printf("a ^ b = %d\n", c); // Output: 19

    // Bitwise NOT
    c = ~a;
    printf("~a = %d\n", c); // Output: -11

    // Left shift operator
    c = a << 2;
    printf("a << 2 = %d\n", c); // Output: 40

    // Right shift operator
    c = b >> 3;
    printf("b >> 3 = %d\n", c); // Output: 3

    // Bitwise AND assignment operator
    a &= b;
    printf("a &= b, a = %d\n", a); // Output: 8

    // Bitwise OR assignment operator
    a |= b;
    printf("a |= b, a = %d\n", a); // Output: 25

    // Bitwise XOR assignment operator
    a ^= b;
    printf("a ^= b, a = %d\n", a); // Output: 18

    // Left shift assignment operator
    a <<= 2;
    printf("a <<= 2, a = %d\n", a); // Output: 72

    // Right shift assignment operator
    b >>= 3;
    printf("b >>= 3, b = %d\n", b); // Output: 3

    return 0;
}