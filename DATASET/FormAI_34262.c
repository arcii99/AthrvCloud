//FormAI DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned int num1 = 0xF0F0F0F0;
    unsigned int num2 = 0x0F0F0F0F;

    // AND operation
    unsigned int andResult = num1 & num2;
    printf("AND result: %X\n", andResult);

    // OR operation
    unsigned int orResult = num1 | num2;
    printf("OR result: %X\n", orResult);

    // XOR operation
    unsigned int xorResult = num1 ^ num2;
    printf("XOR result: %X\n", xorResult);

    // Left shift operation
    unsigned int leftShiftResult = num1 << 4;
    printf("Left shift result: %X\n", leftShiftResult);

    // Right shift operation
    unsigned int rightShiftResult = num1 >> 4;
    printf("Right shift result: %X\n", rightShiftResult);

    // Complement operation
    unsigned int complementResult = ~num1;
    printf("Complement result: %X\n", complementResult);

    // Set operation
    unsigned int setNum = 0x0FFFFFFF;
    setNum |= 0x10000000;
    printf("Set operation result: %X\n", setNum);

    // Clear operation
    unsigned int clearNum = 0xFFFFFFFF;
    clearNum &= 0x00FFFFFF;
    printf("Clear operation result: %X\n", clearNum);

    // Toggle operation
    unsigned int toggleNum = 0xAAAAAAAA;
    toggleNum ^= 0xFFFFFFFF;
    printf("Toggle operation result: %X\n", toggleNum);

    return 0;
}