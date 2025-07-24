//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

int main() {
    unsigned int num1 = 32; // Binary equivalent: 0010 0000
    unsigned int num2 = 15; // Binary equivalent: 0000 1111

    // Bitwise AND operation (&) - returns 1 when both bits are 1
    unsigned int result_and = num1 & num2; // Binary equivalent: 0000 0000 (Decimal equivalent: 0)
    printf("Bitwise AND: %u & %u = %u\n", num1, num2, result_and);

    // Bitwise OR operation (|) - returns 1 when at least one bit is 1
    unsigned int result_or = num1 | num2; // Binary equivalent: 0010 1111 (Decimal equivalent: 47)
    printf("Bitwise OR: %u | %u = %u\n", num1, num2, result_or);

    // Bitwise XOR operation (^) - returns 1 when only one bit is 1
    unsigned int result_xor = num1 ^ num2; // Binary equivalent: 0010 1111 (Decimal equivalent: 47)
    printf("Bitwise XOR: %u ^ %u = %u\n", num1, num2, result_xor);

    // Bitwise NOT operation (~) - reverses all the bits (1 to 0, 0 to 1)
    unsigned int result_not = ~num1; // Binary equivalent: 1101 1111 (Decimal equivalent: 4294967263)
    printf("Bitwise NOT: ~%u = %u\n", num1, result_not);

    // Bitwise left shift operation (<<) - shifts all the bits to the left by the given number of positions
    unsigned int result_left_shift = num1 << 2; // Binary equivalent: 1000 0000 (Decimal equivalent: 128)
    printf("Left shift: %u << 2 = %u\n", num1, result_left_shift);

    // Bitwise right shift operation (>>) - shifts all the bits to the right by the given number of positions
    unsigned int result_right_shift = num1 >> 2; // Binary equivalent: 0000 1000 (Decimal equivalent: 8)
    printf("Right shift: %u >> 2 = %u\n", num1, result_right_shift);

    return 0;
}