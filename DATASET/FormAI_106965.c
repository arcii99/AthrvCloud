//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>

int main() {

    printf("Welcome to the Mind-Bending Bitwise Operations Program!\n");

    int num1 = 27; // binary 00011011
    int num2 = 45; // binary 00101101

    // Bitwise AND operator (&)
    int bitwise_and_result = num1 & num2; // binary 00001001
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, bitwise_and_result);

    // Bitwise OR operator (|)
    int bitwise_or_result = num1 | num2; // binary 00111111
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, bitwise_or_result);

    // Bitwise XOR operator (^)
    int bitwise_xor_result = num1 ^ num2; // binary 00110110
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, bitwise_xor_result);

    // Bitwise NOT operator (~) - bitwise complement of num1
    int bitwise_not_result = ~num1; // binary 11100100
    printf("Bitwise NOT of %d is %d\n", num1, bitwise_not_result);

    // Left shift operator (<<)
    int left_shift_result = num1 << 3; // binary 11011000
    printf("Left shift of %d by 3 bits is %d\n", num1, left_shift_result);

    // Right shift operator (>>)
    int right_shift_result = num2 >> 2; // binary 00001011
    printf("Right shift of %d by 2 bits is %d\n", num2, right_shift_result);

    // Bitwise AND assignment operator (&=)
    num1 &= num2; // binary 00001001
    printf("After Bitwise AND Assignment, num1 is now %d\n", num1);

    // Bitwise OR assignment operator (|=)
    num1 |= num2; // binary 00101101
    printf("After Bitwise OR Assignment, num1 is now %d\n", num1);

    // Bitwise XOR assignment operator (^=)
    num1 ^= num2; // binary 00100100
    printf("After Bitwise XOR Assignment, num1 is now %d\n", num1);

    // Left shift assignment operator (<<=)
    num1 <<= 2; // binary 10010000
    printf("After Left shift Assignment, num1 is now %d\n", num1);

    // Right shift assignment operator (>>=)
    num1 >>= 1; // binary 01001000
    printf("After Right shift Assignment, num1 is now %d\n", num1);

    return 0;
}