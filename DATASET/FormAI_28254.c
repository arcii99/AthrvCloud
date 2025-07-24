//FormAI DATASET v1.0 Category: Bitwise operations ; Style: content
#include <stdio.h>

int main()
{
    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101

    // Bitwise AND
    unsigned int c = a & b; // 0000 1100
    printf("a & b = %u\n", c);

    // Bitwise OR
    c = a | b; // 0011 1101
    printf("a | b = %u\n", c);

    // Bitwise XOR
    c = a ^ b; // 0011 0001
    printf("a ^ b = %u\n", c);

    // One's complement
    c = ~a; // 1100 0011
    printf("~a = %u\n", c);

    // Left shift
    c = a << 2; // 1111 0000
    printf("a << 2 = %u\n", c);

    // Right shift
    c = a >> 2; // 0000 1111
    printf("a >> 2 = %u\n", c);

    return 0;
}