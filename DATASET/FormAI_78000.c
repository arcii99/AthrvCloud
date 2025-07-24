//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
    unsigned char a = 0b1010;
    unsigned char b = 0b0110;

    // Bitwise OR
    unsigned char bitwise_or = a | b;
    printf("OR operator result: %d\nBinary: %d\n", bitwise_or, bitwise_or);

    // Bitwise AND
    unsigned char bitwise_and = a & b;
    printf("AND operator result: %d\nBinary: %d\n", bitwise_and, bitwise_and);

    // Bitwise XOR
    unsigned char bitwise_xor = a ^ b;
    printf("XOR operator result: %d\nBinary: %d\n", bitwise_xor, bitwise_xor);

    // Bitwise NOT
    unsigned char bitwise_not = ~a;
    printf("NOT operator result: %d\nBinary: %d\n", bitwise_not, bitwise_not);

    // Left Shift
    unsigned char left_shift = a << 2;
    printf("Left shift result: %d\nBinary: %d\n", left_shift, left_shift);

    // Right Shift
    unsigned char right_shift = a >> 2;
    printf("Right shift result: %d\nBinary: %d\n", right_shift, right_shift);

    return 0;
}