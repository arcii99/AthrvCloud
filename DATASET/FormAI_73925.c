//FormAI DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QR_SIZE 30

char qrData[MAX_QR_SIZE];
int qrSize;

bool readQRCode (char* code) {
    printf("Enter QR code (maximum of %d characters): ", MAX_QR_SIZE);
    fgets(qrData, MAX_QR_SIZE, stdin);
    qrSize = strlen(qrData) - 1;
    strcpy(code, qrData);
    return true;
}

bool isQRCodeValid (const char* code) {
    if (strlen(code) != qrSize) {
        return false;
    }

    for (int i = 0; i < qrSize; i++) {
        if (code[i] != qrData[i]) {
            return false;
        }
    }

    return true;
}

bool processQRCode (const char* code) {
    if (isQRCodeValid(code)) {
        printf("QR code is valid and processed successfully!\n");
        return true;
    } else {
        printf("QR code is invalid, please try again!\n");
        char newCode[MAX_QR_SIZE];
        readQRCode(newCode);
        processQRCode(newCode);
    }
}

int main() {
    printf("Welcome to QR Code Reader Program!\n");
    char code[MAX_QR_SIZE];
    readQRCode(code);
    processQRCode(code);
    return 0;
}