//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

int main() {
    unsigned int num1 = 0b10101010;
    unsigned int num2 = 0b01010101;

    printf("num1 = %u\n", num1);
    printf("num2 = %u\n\n", num2);

    // Bitwise AND operator
    printf("num1 & num2 = %u\n", num1 & num2);

    // Bitwise OR operator
    printf("num1 | num2 = %u\n", num1 | num2);

    // Bitwise XOR operator
    printf("num1 ^ num2 = %u\n", num1 ^ num2);

    // Bitwise NOT operator
    printf("~num1 = %u\n", ~num1);

    // Left shift operator
    printf("num1 << 3 = %u\n", num1 << 3);

    // Right shift operator
    printf("num1 >> 3 = %u\n", num1 >> 3);

    // Bitwise AND assignment operator
    num1 &= num2;
    printf("num1 &= num2 = %u\n", num1);

    // Bitwise OR assignment operator
    num1 |= num2;
    printf("num1 |= num2 = %u\n", num1);

    // Bitwise XOR assignment operator
    num1 ^= num2;
    printf("num1 ^= num2 = %u\n\n", num1);

    printf("Thank you for using the Bitwise operations program!\n");

    return 0;
}