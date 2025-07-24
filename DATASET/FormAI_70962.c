//FormAI DATASET v1.0 Category: Bitwise operations ; Style: content
#include <stdio.h>

// Function to display bits of a number
void displayBits(unsigned int num) {
    // Number of bits in integer
    int n = sizeof(num) * 8;

    // Loop to print bits one by one from left to right
    for (int i = n - 1; i >= 0; i--) {
        if ((num >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main() {
    int num1 = 583; // 1001000111
    int num2 = 826; // 1100111010

    printf("num1: ");
    displayBits(num1);
    printf("\nnum2: ");
    displayBits(num2);

    // Bitwise AND operation
    int andResult = num1 & num2;
    printf("\n\nnum1 & num2: ");
    displayBits(andResult);
    printf("\nEquivalent decimal value: %d", andResult);

    // Bitwise OR operation
    int orResult = num1 | num2;
    printf("\n\nnum1 | num2: ");
    displayBits(orResult);
    printf("\nEquivalent decimal value: %d", orResult);

    // Bitwise XOR operation
    int xorResult = num1 ^ num2;
    printf("\n\nnum1 ^ num2: ");
    displayBits(xorResult);
    printf("\nEquivalent decimal value: %d", xorResult);

    // Bitwise NOT operation
    int notResult1 = ~num1;
    printf("\n\n~num1: ");
    displayBits(notResult1);
    printf("\nEquivalent decimal value: %d", notResult1);

    int notResult2 = ~num2;
    printf("\n\n~num2: ");
    displayBits(notResult2);
    printf("\nEquivalent decimal value: %d", notResult2);

    // Bitwise left shift operation
    int shiftLeftResult = num1 << 3;
    printf("\n\nnum1 << 3: ");
    displayBits(shiftLeftResult);
    printf("\nEquivalent decimal value: %d", shiftLeftResult);

    // Bitwise right shift operation
    int shiftRightResult = num2 >> 4;
    printf("\n\nnum2 >> 4: ");
    displayBits(shiftRightResult);
    printf("\nEquivalent decimal value: %d", shiftRightResult);

    return 0;
}