//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

int main() {
    unsigned int a = 60;  // 00111100 in binary
    unsigned int b = 13;  // 00001101 in binary
    unsigned int c = 0;

    // Bitwise AND (&) operation
    c = a & b;  // 00001100 in binary
    printf("a & b = %u\n", c);

    // Bitwise OR (|) operation
    c = a | b;  // 00111101 in binary
    printf("a | b = %u\n", c);

    // Bitwise XOR (^) operation
    c = a ^ b;  // 00110001 in binary
    printf("a ^ b = %u\n", c);

    // Bitwise NOT (~) operation
    c = ~a;  // 11000011 in binary
    printf("~a = %u\n", c);

    // Bitwise LEFT SHIFT (<<) operation
    c = a << 2;  // 11110000 in binary
    printf("a << 2 = %u\n", c);

    // Bitwise RIGHT SHIFT (>>) operation
    c = a >> 2;  // 00001111 in binary
    printf("a >> 2 = %u\n", c);

    return 0;
}