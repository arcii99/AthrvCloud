//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program converts decimal numbers to binary numbers. The user inputs
the ASCII value (character input) of the decimal number and the program
output's the binary number. */

void binaryConverter(int decimalNum) {
    // Initialize variables
    int remainder, binaryNum = 0, i = 1;

    // Convert decimal to binary
    while(decimalNum != 0) {
        remainder = decimalNum % 2;
        decimalNum /= 2;
        binaryNum += remainder * i;
        i *= 10;
    }

    // Print the binary number
    printf("The binary representation of the decimal number is: %d\n", binaryNum);
}

int main() {
    // Initialize variables
    int decimalNum;

    // Get user input
    printf("Enter the decimal number to be converted to binary: ");
    scanf("%d", &decimalNum);

    // Call the binary converter function
    binaryConverter(decimalNum);

    return 0;
}