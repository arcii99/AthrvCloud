//FormAI DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define a maximum buffer size for storing the binary number
#define MAX_BUFFER_SIZE 32

// Define a function to convert a decimal number to a binary number
void decimalToBinary(unsigned int decimalNumber, char* binaryNumber) {
    int i = 0;

    // Divide the decimal number by 2 and store the remainder in the binary buffer
    while (decimalNumber > 0) {
        binaryNumber[i++] = (decimalNumber % 2) + '0';
        decimalNumber /= 2;
    }

    // Add padding zeros to the binary buffer to make it a multiple of 4 bits
    while (i % 4 != 0) {
        binaryNumber[i++] = '0';
    }

    // Reverse the binary buffer to get the correct binary number
    for (int j = 0; j < i / 2; j++) {
        char temp = binaryNumber[j];
        binaryNumber[j] = binaryNumber[i - j - 1];
        binaryNumber[i - j - 1] = temp;
    }

    // Terminate the binary buffer with a null character
    binaryNumber[i] = '\0';
}

int main() {
    unsigned int decimalNumber;
    char binaryNumber[MAX_BUFFER_SIZE];

    // Prompt the user for a decimal number
    printf("Enter a decimal number: ");
    scanf("%u", &decimalNumber);

    // Convert the decimal number to a binary number
    decimalToBinary(decimalNumber, binaryNumber);

    // Print the binary number to the console
    printf("Binary number: %s\n", binaryNumber);

    return 0;
}