//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>

int main() {
    unsigned int a = 7; // 0000 0111
    unsigned int b = 12; // 0000 1100
    unsigned int c;

    printf("a = %u\n", a);
    printf("b = %u\n", b);

    // Bitwise AND
    c = a & b; // 0000 0100
    printf("a & b = %u\n", c);

    // Bitwise OR
    c = a | b; // 0000 1111
    printf("a | b = %u\n", c);

    // Bitwise XOR
    c = a ^ b; // 0000 1011
    printf("a ^ b = %u\n", c);

    // Bitwise NOT
    c = ~a; // 1111 1000
    printf("~a = %u\n", c);

    // Left Shift
    c = a << 1; // 0000 1110
    printf("a << 1 = %u\n", c);

    // Right Shift
    c = b >> 1; // 0000 0110
    printf("b >> 1 = %u\n", c);

    // Bitwise AND with masks
    unsigned char num = 0b10111010; // 186 (decimal)
    unsigned char mask = 0b00001111; // 15 (decimal)
    unsigned char masked = num & mask; // 10 (decimal)
    printf("num & mask = %u\n", masked);

    return 0;
}