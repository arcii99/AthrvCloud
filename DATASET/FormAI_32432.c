//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include<stdio.h>

int main()
{
    /* Bitwise AND: If both bits are 1, the result is 1. Otherwise, it is 0. */
    unsigned int a = 60; // 0011 1100 binary
    unsigned int b = 13; // 0000 1101 binary
    unsigned int c = a & b; // 0000 1100 binary

    printf("a & b = %u\n", c); // Output: a & b = 12

    /* Bitwise OR: If either of the two bits is 1, the result is 1. Otherwise, it is 0. */
    unsigned int d = a | b; // 0011 1101 binary

    printf("a | b = %u\n", d); // Output: a | b = 61

    /* Bitwise XOR: If the two bits are different, the result is 1. Otherwise, it is 0. */
    unsigned int e = a ^ b; // 0011 0001 binary

    printf("a ^ b = %u\n", e); // Output: a ^ b = 49

    /* Bitwise NOT: Flips all the bits */
    unsigned int f = ~a; // 1100 0011 binary

    printf("~a = %u\n", f); // Output: ~a = 4294967235

    /* Bitwise Left Shift: Shifts the bits to the left by the specified number of positions*/
    unsigned int g = a << 2; // 1111 0000 binary

    printf("a << 2 = %u\n", g); // Output: a << 2 = 240

    /* Bitwise Right Shift: Shifts the bits to the right by the specified number of positions*/
    unsigned int h = a >> 2; // 0000 1111 binary

    printf("a >> 2 = %u\n", h); // Output: a >> 2 = 15

    return 0;
}