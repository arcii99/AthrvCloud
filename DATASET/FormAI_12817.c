//FormAI DATASET v1.0 Category: Bitwise operations ; Style: secure
#include <stdio.h>

int main()
{
    unsigned int a = 60; // 0011 1100 in binary
    unsigned int b = 13; // 0000 1101 in binary
    int result = 0;

    // Bitwise AND - sets each bit to 1 only if both bits are 1
    result = a & b; // 0000 1100
    printf("a & b = %d\n", result);

    // Bitwise OR - sets each bit to 1 if either or both bits are 1
    result = a | b; // 0011 1101
    printf("a | b = %d\n", result);

    // Bitwise XOR - sets each bit to 1 if only one of the two bits is 1
    result = a ^ b; // 0011 0001
    printf("a ^ b = %d\n", result);

    // Bitwise NOT - inverts all the bits
    result = ~a; // 1100 0011
    printf("~a = %d\n", result);

    // Left shift - shifts all the bits to the left by the specified number of positions
    result = a << 2; // 1111 0000
    printf("a << 2 = %d\n", result);

    // Right shift - shifts all the bits to the right by the specified number of positions
    result = a >> 2; // 0000 1111
    printf("a >> 2 = %d\n", result);

    // Bitwise AND with mask
    unsigned int mask = 0x0F; // 00001111 in binary
    result = a & mask; // 00001100
    printf("a & mask = %d\n", result);

    // Bitwise OR with mask
    result = a | mask; // 00111111
    printf("a | mask = %d\n", result);

    // Bitwise XOR with mask
    result = a ^ mask; // 00110011
    printf("a ^ mask = %d\n", result);

    return 0;
}