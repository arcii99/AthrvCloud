//FormAI DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>

int main() {
    // Bitwise AND operator
    int num1 = 10, num2 = 15;
    int result = num1 & num2;
    printf("Bitwise AND of %d and %d = %d\n", num1, num2, result);

    // Bitwise OR operator
    result = num1 | num2;
    printf("Bitwise OR of %d and %d = %d\n", num1, num2, result);

    // Bitwise XOR operator
    result = num1 ^ num2;
    printf("Bitwise XOR of %d and %d = %d\n", num1, num2, result);

    // Bitwise NOT operator
    result = ~num1;
    printf("Bitwise NOT of %d = %d\n", num1, result);

    // Bitwise Left Shift operator
    int shift1 = num1 << 2;
    printf("Bitwise Left Shift of %d by 2 = %d\n", num1, shift1);

    // Bitwise Right Shift operator
    int shift2 = num2 >> 1;
    printf("Bitwise Right Shift of %d by 1 = %d\n", num2, shift2);

    // Bitwise AND assignment operator
    num1 &= num2;
    printf("Bitwise AND Assignment of %d and %d = %d\n", num1, num2, num1);

    // Bitwise OR assignment operator
    num1 |= num2;
    printf("Bitwise OR Assignment of %d and %d = %d\n", num1, num2, num1);

    // Bitwise XOR assignment operator
    num1 ^= num2;
    printf("Bitwise XOR Assignment of %d and %d = %d\n", num1, num2, num1);

    // Bitwise Left Shift assignment operator
    num1 <<= 2;
    printf("Bitwise Left Shift Assignment of %d by 2 = %d\n", num1, num1);

    // Bitwise Right Shift assignment operator
    num1 >>= 1;
    printf("Bitwise Right Shift Assignment of %d by 1 = %d\n", num1, num1);

    return 0;
}