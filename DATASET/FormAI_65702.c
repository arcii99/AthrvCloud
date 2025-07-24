//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

// A program to demonstrate the bitwise operations in C

int main() {
    int num1, num2, andResult, orResult, xorResult, leftShiftResult, rightShiftResult;

    printf("Welcome to the Bitwise Operations Program!\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2); // Taking input from the user

    // Performing bitwise AND operation
    andResult = num1 & num2;
    printf("\nBitwise AND operation result: %d\n", andResult);

    // Performing bitwise OR operation
    orResult = num1 | num2;
    printf("\nBitwise OR operation result: %d\n", orResult);

    // Performing bitwise XOR operation
    xorResult = num1 ^ num2;
    printf("\nBitwise XOR operation result: %d\n", xorResult);

    // Performing bitwise left shift operation
    printf("\nEnter number of bits to left shift: ");
    int leftShiftBits;
    scanf("%d", &leftShiftBits);
    leftShiftResult = num1 << leftShiftBits;
    printf("Result of left shift operation: %d\n", leftShiftResult);

    // Performing bitwise right shift operation
    printf("\nEnter number of bits to right shift: ");
    int rightShiftBits;
    scanf("%d", &rightShiftBits);
    rightShiftResult = num2 >> rightShiftBits;
    printf("Result of right shift operation: %d\n", rightShiftResult);

    printf("\nHope you had fun playing with the Bitwise Operations Program!\n");

    return 0;
}