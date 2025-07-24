//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>

int main() {
    unsigned int num1 = 0b10101010; // Binary representation of 170
    unsigned int num2 = 0b11110000; // Binary representation of 240

    // Bitwise AND operator (&)
    unsigned int result_and = num1 & num2;
    printf("Bitwise AND (&):\t\t0x%X & 0x%X = 0x%X\n", num1, num2, result_and);

    // Bitwise OR operator (|)
    unsigned int result_or = num1 | num2;
    printf("Bitwise OR (|):\t\t\t0x%X | 0x%X = 0x%X\n", num1, num2, result_or);

    // Bitwise XOR operator (^)
    unsigned int result_xor = num1 ^ num2;
    printf("Bitwise XOR (^):\t\t0x%X ^ 0x%X = 0x%X\n", num1, num2, result_xor);

    // Bitwise NOT operator (~)
    unsigned int result_not = ~num1;
    printf("Bitwise NOT (~):\t\t~0x%X = 0x%X\n", num1, result_not);

    // Left shift operator (<<)
    unsigned int result_left_shift = num1 << 2;
    printf("Left shift (<<):\t\t\t0x%X << 2 = 0x%X\n", num1, result_left_shift);

    // Right shift operator (>>)
    unsigned int result_right_shift = num2 >> 3;
    printf("Right shift (>>):\t\t0x%X >> 3 = 0x%X\n", num2, result_right_shift);

    return 0;
}