//FormAI DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>

int main() {
    unsigned int a = 60;
    unsigned int b = 13;
    int result;

    // Bitwise AND operator, compares each corresponding bit of both operands
    result = a & b;
    printf("a & b = %d\n", result);

    // Bitwise OR operator, compares each corresponding bit of both operands
    result = a | b;
    printf("a | b = %d\n", result);

    // Bitwise XOR operator, compares each corresponding bit of both operands
    result = a ^ b;
    printf("a ^ b = %d\n", result);

    // Bitwise Complement operator, inverts each bit of the operand
    result = ~a;
    printf("~a = %d\n", result);

    // Bitwise Left Shift operator, shifts the bits of the operand to the left by a certain number of positions
    result = a << 2;
    printf("a << 2 = %d\n", result);

    // Bitwise Right Shift operator, shifts the bits of the operand to the right by a certain number of positions
    result = a >> 2;
    printf("a >> 2 = %d\n", result);

    return 0;
}