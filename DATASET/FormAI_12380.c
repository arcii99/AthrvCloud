//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Helper function to convert decimal to hexadecimal
char getHexChar(int num) {
    if (num >= 0 && num <= 9) {
        return num + '0'; // Convert digit to character
    } else {
        return num - 10 + 'A'; // Convert number from 10 to 15 to corresponding letter in hexadecimal
    }
}

// Main function that converts decimal to hexadecimal
void decToHex(int decimal) {
    char hex[7]; // Hexadecimal strings can have up to 6 characters plus null terminator
    int i = 0;

    while (decimal != 0) {
        int remainder = decimal % 16;
        hex[i++] = getHexChar(remainder); // Add next hexadecimal digit to string
        decimal /= 16;
    }

    if (i == 0) { // If decimal is 0, the result is "0"
        hex[i++] = '0';
    }
    hex[i] = '\0'; // Add null terminator to end of string

    printf("The hexadecimal equivalent is: 0x%s\n", hex); // Print the result
}

int main() {
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Please enter a decimal number to convert: ");

    int decimal;
    scanf("%d", &decimal); // Get decimal input from user
    printf("Converting decimal %d...\n\n", decimal);

    decToHex(decimal); // Convert decimal to hexadecimal

    printf("\nThank you for using the Decimal to Hexadecimal Converter!\n");

    return 0;
}