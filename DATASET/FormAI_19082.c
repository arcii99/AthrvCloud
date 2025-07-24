//FormAI DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

int main() {
    // Set up some initial values
    unsigned char a = 0b11001100; // 204
    unsigned char b = 0b10101010; // 170
    unsigned char c;

    // Print out the initial values
    printf("a = %d (%x)\nb = %d (%x)\n", a, a, b, b);

    // Bitwise AND
    c = a & b;
    printf("Bitwise AND: %d (%x)\n", c, c);

    // Bitwise OR
    c = a | b;
    printf("Bitwise OR: %d (%x)\n", c, c);

    // Bitwise XOR
    c = a ^ b;
    printf("Bitwise XOR: %d (%x)\n", c, c);

    // Bitwise NOT
    c = ~a;
    printf("Bitwise NOT (a): %d (%x)\n", c, c);
    c = ~b;
    printf("Bitwise NOT (b): %d (%x)\n", c, c);

    // Bitwise Left Shift
    c = a << 2;
    printf("Bitwise Left Shift: %d (%x)\n", c, c);

    // Bitwise Right Shift
    c = b >> 3;
    printf("Bitwise Right Shift: %d (%x)\n", c, c);

    // Bitwise AND with constant
    c = a & 0b11110000;
    printf("Bitwise AND (constant): %d (%x)\n", c, c);

    // Bitwise OR with constant
    c = b | 0b00001111;
    printf("Bitwise OR (constant): %d (%x)\n", c, c);

    // Bitwise XOR with constant
    c = a ^ 0b01010101;
    printf("Bitwise XOR (constant): %d (%x)\n", c, c);

    return 0;
}