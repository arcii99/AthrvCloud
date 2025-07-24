//FormAI DATASET v1.0 Category: QR code reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Define constant for maximum length of string
#define MAX_LENGTH 1000

// Define function to check if character is a valid hex character
bool isHexChar(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
        return true;
    } else {
        return false;
    }
}

// Define function to convert hex string to decimal number
uint32_t hexToDec(char hexString[]) {
    uint32_t decimal = 0;
    int length = strlen(hexString);
    for (int i = 0; i < length; i++) {
        if (isHexChar(hexString[i])) {
            uint32_t digit;
            if (hexString[i] >= '0' && hexString[i] <= '9') {
                digit = hexString[i] - '0';
            } else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
                digit = hexString[i] - 'A' + 10;
            } else if (hexString[i] >= 'a' && hexString[i] <= 'f') {
                digit = hexString[i] - 'a' + 10;
            }
            decimal += digit * pow(16, length - 1 - i);
        } else {
            printf("Error: Invalid hex character '%c' at position %d\n", hexString[i], i);
            exit(EXIT_FAILURE);
        }
    }
    return decimal;
}

// Define main function
int main() {
    // Ask user to input QR code
    printf("Please enter your QR code (max %d characters): ", MAX_LENGTH);
    char qrCode[MAX_LENGTH];
    fgets(qrCode, MAX_LENGTH, stdin);
    // Remove trailing newline from input
    qrCode[strcspn(qrCode, "\n")] = 0;
    // Check if QR code is exactly 64 characters
    if (strlen(qrCode) != 64) {
        printf("Error: QR code must be exactly 64 characters\n");
        exit(EXIT_FAILURE);
    }
    // Check if QR code contains only valid hex characters
    for (int i = 0; i < 64; i++) {
        if (!isHexChar(qrCode[i])) {
            printf("Error: Invalid hex character '%c' at position %d\n", qrCode[i], i);
            exit(EXIT_FAILURE);
        }
    }
    // Convert QR code to decimal numbers
    uint32_t decimal[16];
    for (int i = 0; i < 16; i++) {
        char hexString[5];
        hexString[0] = qrCode[i*4];
        hexString[1] = qrCode[i*4+1];
        hexString[2] = qrCode[i*4+2];
        hexString[3] = qrCode[i*4+3];
        hexString[4] = '\0';
        decimal[i] = hexToDec(hexString);
    }
    // Print out the decimal numbers
    printf("The decimal numbers in the QR code are:\n");
    for (int i = 0; i < 16; i++) {
        printf("%u ", decimal[i]);
    }
    printf("\n");
    return 0;
}