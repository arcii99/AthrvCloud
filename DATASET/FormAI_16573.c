//FormAI DATASET v1.0 Category: QR code reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QRCode {
    char code[100];
} QRCode;

void readCode(QRCode *qrCode) {
    printf("Enter QR code: ");
    fgets(qrCode->code, 100, stdin);
    qrCode->code[strcspn(qrCode->code, "\n")] = 0; // remove trailing newline character
}

void parseCode(QRCode qrCode) {
    char *token = strtok(qrCode.code, ",");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
}

int main() {
    QRCode qrCode;

    readCode(&qrCode);

    parseCode(qrCode);

    return 0;
}