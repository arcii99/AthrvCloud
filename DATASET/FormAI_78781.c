//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Claude Shannon
#include<stdio.h>

int main()
{
    unsigned int num1 = 9; // Binary 1001
    unsigned int num2 = 12; // Binary 1100
    unsigned int result;

    // Bitwise AND operation
    result = num1 & num2; // Binary 1000 = Decimal 8
    printf("Bitwise AND Result: %u\n", result);

    // Bitwise OR operation
    result = num1 | num2; // Binary 1101 = Decimal 13
    printf("Bitwise OR Result: %u\n", result);

    // Bitwise XOR operation
    result = num1 ^ num2; // Binary 0101 = Decimal 5
    printf("Bitwise XOR Result: %u\n", result);

    // Bitwise NOT operation
    result = ~num1; // Binary 0110 = Decimal 6
    printf("Bitwise NOT Result (num1): %u\n", result);

    // Bitwise Shift Left operation
    result = num1 << 2; // Binary 100100 = Decimal 36
    printf("Bitwise Shift Left Result: %u\n", result);

    // Bitwise Shift Right operation
    result = num2 >> 2; // Binary 0011 = Decimal 3
    printf("Bitwise Shift Right Result: %u\n", result);

    return 0;
}