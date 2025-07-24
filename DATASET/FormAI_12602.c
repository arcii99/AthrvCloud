//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

int main() {
    int number1 = 5; // 0101 in binary
    int number2 = 3; // 0011 in binary

    // Bitwise AND operator
    int bitwiseAnd = number1 & number2; // 0001
    printf("Bitwise AND result: %d\n", bitwiseAnd);

    // Bitwise OR operator
    int bitwiseOr = number1 | number2; // 0111
    printf("Bitwise OR result: %d\n", bitwiseOr);

    // Bitwise XOR operator
    int bitwiseXor = number1 ^ number2; // 0110
    printf("Bitwise XOR result: %d\n", bitwiseXor);

    // Bitwise NOT operator
    int bitwiseNot = ~number1; // 1010
    printf("Bitwise NOT of %d is %d\n", number1, bitwiseNot);

    // Bitwise left shift operator
    int bitwiseLeftShift = number1 << 1; // 1010
    printf("Bitwise left shift result: %d\n", bitwiseLeftShift);

    // Bitwise right shift operator
    int bitwiseRightShift = number1 >> 1; // 0010
    printf("Bitwise right shift result: %d\n", bitwiseRightShift);

    return 0;
}