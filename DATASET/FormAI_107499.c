//FormAI DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_LENGTH 32 // Maximum length of binary input

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base; // Calculate power by multiplying base the required number of times
    }
    return result;
}

int binaryToDecimal(char* binary) {
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += power(2, length - 1 - i); // Calculate decimal by adding 2^i
        }
    }
    return decimal;
}

int main() {
    char binary[BINARY_LENGTH];
    printf("Enter a binary number: ");
    fgets(binary, BINARY_LENGTH, stdin); // Get binary input from user
    binary[strcspn(binary, "\n")] = '\0'; // Remove newline character from input
    
    if (strlen(binary) > BINARY_LENGTH - 1) {
        printf("Error: Input length exceeds maximum length of %d.\n", BINARY_LENGTH - 1);
    } else {
        int decimal = binaryToDecimal(binary);
        printf("%s in binary is equal to %d in decimal.\n", binary, decimal);
    }
    
    return 0;
}