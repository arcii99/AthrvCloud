//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 100

typedef struct {
    char data[MAX_QR_CODE_LENGTH];
    int length;
} QRCode;

QRCode readQRCode() {
    QRCode code;
    printf("Enter a QR Code (max length %d): ", MAX_QR_CODE_LENGTH);
    fgets(code.data, MAX_QR_CODE_LENGTH, stdin);
    code.data[strcspn(code.data, "\n")] = '\0'; // remove trailing newline
    code.length = strlen(code.data);
    return code;
}

bool validateQRCode(QRCode code) {
    if (code.length % 2 != 0) {
        return false; // length must be even
    }
    for (int i = 0; i < code.length; i++) {
        if (!isxdigit(code.data[i])) {
            return false; // must be a hex digit
        }
    }
    return true;
}

unsigned char hexToByte(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return toupper(c) - 'A' + 10;
    }
}

void decodeQRCode(QRCode code) {
    printf("Decoded message: ");
    for (int i = 0; i < code.length; i += 2) {
        unsigned char byte = (hexToByte(code.data[i]) << 4) | hexToByte(code.data[i + 1]);
        printf("%c", byte);
    }
    printf("\n");
}

int main() {
    QRCode code = readQRCode();
    if (!validateQRCode(code)) {
        printf("Invalid QR Code\n");
        exit(1);
    }
    decodeQRCode(code);
    return 0;
}