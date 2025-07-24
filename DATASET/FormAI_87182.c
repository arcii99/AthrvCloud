//FormAI DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>

int main() {
    unsigned int x = 42;
    unsigned int y = 69;
    unsigned int z = 0;
    unsigned int a = 127;
    unsigned int b = 255;

    // Bitwise AND operation
    z = x & y;
    printf("x & y = %u\n", z);

    // Bitwise OR operation
    z = x | y;
    printf("x | y = %u\n", z);

    // Bitwise negation
    z = ~x;
    printf("~x = %u\n", z);

    // Left shift
    z = a << 1;
    printf("a << 1 = %u\n", z);

    // Right shift
    z = b >> 1;
    printf("b >> 1 = %u\n", z);

    // Bitwise XOR operation
    z = x ^ y;
    printf("x ^ y = %u\n", z);

    // Bitwise AND assignment
    x &= y;
    printf("x &= y, x = %u\n", x);

    // Bitwise OR assignment
    x |= y;
    printf("x |= y, x = %u\n", x);

    // Left shift assignment
    a <<= 1;
    printf("a <<= 1, a = %u\n", a);

    // Right shift assignment
    b >>= 1;
    printf("b >>= 1, b = %u\n", b);

    // Bitwise XOR assignment
    x ^= y;
    printf("x ^= y, x = %u\n", x);

    return 0;
}