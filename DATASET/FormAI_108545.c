//FormAI DATASET v1.0 Category: QR code reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 29  // Size of the QR code

int readQRCode(char* qrCode) {
    printf("Enter the QR code: ");
    fgets(qrCode, QR_CODE_SIZE + 1, stdin);
    int len = strlen(qrCode);
    if (qrCode[len - 1] == '\n') {
        qrCode[len - 1] = '\0';
        len--;
    }
    if (len != QR_CODE_SIZE) {
        return 0;
    }
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        if (qrCode[i] != '0' && qrCode[i] != '1') {
            return 0;
        }
    }
    return 1;
}

void printQRCode(char* qrCode) {
    printf("\nQR code:\n");
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        printf("%c", qrCode[i]);
        if ((i + 1) % 3 == 0) {
            printf(" ");
        }
        if ((i + 1) % 9 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    char qrCode[QR_CODE_SIZE + 1];
    int success = readQRCode(qrCode);
    if (!success) {
        printf("Invalid QR code\n");
        return 1;
    }
    printQRCode(qrCode);
    return 0;
}