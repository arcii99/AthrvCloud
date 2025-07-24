//FormAI DATASET v1.0 Category: QR code reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define maximum length of QR code
#define MAX_QR_LENGTH 100

// Function to check whether a given character is a valid QR code character
bool isQRCodeChar(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Function to read a QR code string from the user
void readQRCode(char* qrCode) {
    printf("Please enter the QR code:\n");
    fgets(qrCode, MAX_QR_LENGTH, stdin);

    // Remove newline character at the end
    qrCode[strcspn(qrCode, "\n")] = '\0';
}

// Function to parse the QR code string and display the result
void parseQRCode(char* qrCode) {
    printf("Parsed QR code:\n");

    // Iterate over each character in the QR code
    for (int i = 0; i < strlen(qrCode); i++) {
        char c = qrCode[i];

        // Ignore any non-QR code characters
        if (!isQRCodeChar(c)) {
            continue;
        }

        // Display the QR code character
        printf("%c ", c);
    }

    printf("\n");
}

// Main function
int main() {
    char qrCode[MAX_QR_LENGTH];

    while (true) {
        readQRCode(qrCode);

        // Exit the program if the user enters 'exit'
        if (strcmp(qrCode, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        }

        parseQRCode(qrCode);
    }

    return 0;
}