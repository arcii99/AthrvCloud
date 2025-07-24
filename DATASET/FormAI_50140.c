//FormAI DATASET v1.0 Category: QR code reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 1000

// Function to check if the QR code is valid or not
bool isQRCodeValid(char qrCode[]) {
    // Check if the QR code starts with "QR_CODE:"
    if (strncmp(qrCode, "QR_CODE:", 8) != 0) {
        return false;
    }

    // Check if the length of the QR code is less than or equal to MAX_QR_CODE_LENGTH
    if (strlen(qrCode) > MAX_QR_CODE_LENGTH) {
        return false;
    }

    // Check if the QR code ends with ";"
    if (qrCode[strlen(qrCode)-1] != ';') {
        return false;
    }

    // If all the above conditions are met, the QR code is valid
    return true;
}

// Function to read the QR code
void readQRCode() {
    char qrCode[MAX_QR_CODE_LENGTH+1];

    // Read the QR code from the user
    printf("Enter the QR code: ");
    fgets(qrCode, MAX_QR_CODE_LENGTH+1, stdin);

    // Remove the newline character from the end of the QR code
    int len = strlen(qrCode);
    if (len > 0 && qrCode[len-1] == '\n') {
        qrCode[len-1] = '\0';
    }

    // Check if the QR code is valid
    if (isQRCodeValid(qrCode)) {
        // If the QR code is valid, print the message
        printf("QR code is valid. Message: %s\n", qrCode+8);
    } else {
        // If the QR code is invalid, print the error message
        printf("Invalid QR code.\n");
    }
}

int main() {
    // Read the QR code and print the message
    readQRCode();

    return 0;
}