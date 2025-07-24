//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    if (num > 1)
        printBinary(num / 2);
    printf("%d", num % 2);
}

int main() {
    // Variables
    unsigned int num1 = 23;
    unsigned int num2 = 15;
    unsigned int result;

    // Bitwise OR operation
    result = num1 | num2;
    printf("\nBinary value of %d: ", num1);
    printBinary(num1);
    printf("\nBinary value of %d: ", num2);
    printBinary(num2);
    printf("\nBitwise OR: ");
    printBinary(result);

    // Bitwise AND operation
    result = num1 & num2;
    printf("\nBitwise AND: ");
    printBinary(result);

    // Bitwise XOR operation
    result = num1 ^ num2;
    printf("\nBitwise XOR: ");
    printBinary(result);

    // Bitwise NOT operation
    result = ~num1;
    printf("\nBitwise NOT of %d: ", num1);
    printBinary(result);

    // Bitwise Left Shift operation
    result = num1 << 2;
    printf("\nBitwise Left Shift of %d: ", num1);
    printBinary(result);

    // Bitwise Right Shift operation
    result = num1 >> 2;
    printf("\nBitwise Right Shift of %d: ", num1);
    printBinary(result);

    return 0;
}