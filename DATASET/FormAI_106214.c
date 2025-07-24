//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

int main() {
    unsigned int a = 27;  // Binary: 00011011
    unsigned int b = 13;  // Binary: 00001101

    // Bitwise AND
    unsigned int c = a & b;  // Binary: 00001001
    printf("a & b = %u\n", c);

    // Bitwise OR
    unsigned int d = a | b;  // Binary: 00011111
    printf("a | b = %u\n", d);

    // Bitwise XOR
    unsigned int e = a ^ b;  // Binary: 00010110
    printf("a ^ b = %u\n", e);

    // Bitwise NOT
    unsigned int f = ~a;  // Binary: 11100100
    printf("~a = %u\n", f);

    // Bitwise LEFT SHIFT
    unsigned int g = a << 2;  // Binary: 01101100
    printf("a << 2 = %u\n", g);

    // Bitwise RIGHT SHIFT
    unsigned int h = a >> 2;  // Binary: 00000110
    printf("a >> 2 = %u\n", h);

    return 0;
}