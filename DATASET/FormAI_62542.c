//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include<stdio.h>

// This is a program to perform bitwise operations
// on two user-entered integer values

int main() {

    int num1, num2, andVal, orVal, xorVal, leftShiftVal, rightShiftVal, complementVal;

    // Ask user for input
    printf("Enter the first integer value: ");
    scanf("%d", &num1);

    printf("Enter the second integer value: ");
    scanf("%d", &num2);

    // Perform the AND operation
    andVal = num1 & num2;
    printf("\n%d & %d = %d\n", num1, num2, andVal);

    // Perform the OR operation
    orVal = num1 | num2;
    printf("%d | %d = %d\n", num1, num2, orVal);

    // Perform the XOR operation
    xorVal = num1 ^ num2;
    printf("%d ^ %d = %d\n", num1, num2, xorVal);

    // Perform the left shift operation
    leftShiftVal = num1 << 2;
    printf("%d << 2 = %d\n", num1, leftShiftVal);

    // Perform the right shift operation
    rightShiftVal = num2 >> 3;
    printf("%d >> 3 = %d\n", num2, rightShiftVal);

    // Perform the complement operation
    complementVal = ~num1;
    printf("~%d = %d\n", num1, complementVal);

    return 0;
}