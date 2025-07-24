//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
/* 
This program demonstrates the use of bitwise operations in C,
including AND, OR, XOR, LEFT SHIFT and RIGHT SHIFT.

The program takes two numbers as inputs from the user. It then 
displays the bitwise AND, bitwise OR, bitwise XOR, left shift and
right shift of the numbers.

*/
#include <stdio.h>

int main() {

    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int bitwiseAnd = num1 & num2;
    int bitwiseOr = num1 | num2;
    int bitwiseXor = num1 ^ num2;
    int leftShift = num1 << 2;
    int rightShift = num2 >> 2;

    printf("\nBitwise AND of %d and %d is %d\n", num1, num2, bitwiseAnd);
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, bitwiseOr);
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, bitwiseXor);
    printf("Left Shift of %d by 2 is %d\n", num1, leftShift);
    printf("Right Shift of %d by 2 is %d\n", num2, rightShift);

    return 0;
}