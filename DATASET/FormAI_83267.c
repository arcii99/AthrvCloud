//FormAI DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

/* Bitwise operations example program */

int main() {
    unsigned char x = 75; // binary representation: 01001011
    unsigned char y = 38; // binary representation: 00100110
    unsigned char result;

    // AND operator (&) example
    result = x & y; // binary representation: 00000010
    printf("x & y = %d\n", result); // expected output: 2

    // OR operator (|) example
    result = x | y; // binary representation: 01101111
    printf("x | y = %d\n", result); // expected output: 111

    // XOR operator (^) example
    result = x ^ y; // binary representation: 01101101
    printf("x ^ y = %d\n", result); // expected output: 109

    // Complement operator (~) example
    result = ~x; // binary representation: 10110100
    printf("~x = %d\n", result); // expected output: 180

    // Left shift operator (<<) example
    result = x << 2; // binary representation: 00101100
    printf("x << 2 = %d\n", result); // expected output: 44

    // Right shift operator (>>) example
    result = y >> 3; // binary representation: 00000100
    printf("y >> 3 = %d\n", result); // expected output: 4

    return 0;
}