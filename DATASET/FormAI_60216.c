//FormAI DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

int main() {

    // Bitwise example program using XOR, shift and mask operations

    // Declare variables
    unsigned int num1 = 0x5A; // hexadecimal value
    unsigned int num2 = 0xB3; // hexadecimal value
    unsigned int result;

    // XOR operation
    result = num1 ^ num2;
    printf("The result of XOR operation is: 0x%X\n", result);

    // Left shift operation
    result = num1 << 3;
    printf("The result of left shift operation is: 0x%X\n", result);

    // Right shift operation
    result = num2 >> 2;
    printf("The result of right shift operation is: 0x%X\n", result);

    // Mask operation
    result = num1 & 0x0F; // mask with lower nibble
    printf("The result of mask operation is: 0x%X\n", result);

    return 0;
}