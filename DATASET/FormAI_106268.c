//FormAI DATASET v1.0 Category: QR code reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int length;
    char data[SIZE];
} QRCode;

void readQRCode(QRCode* qrCode, char* input) {
    qrCode->length = strlen(input);
    strcpy(qrCode->data, input);
}

void decodeQRCode(QRCode qrCode) {
    char message[SIZE] = { 0 };

    for (int i = 0; i < qrCode.length; i += 2) {
        message[i / 2] = qrCode.data[i] + qrCode.data[i + 1];
    }

    printf("The decoded message is: %s\n", message);
}

int main() {
    char input[SIZE] = { 0 };
    printf("Enter a string that represents a QR code: ");
    scanf("%s", input);

    QRCode qrCode;
    readQRCode(&qrCode, input);

    printf("Decoding QR code...\n");
    decodeQRCode(qrCode);

    return 0;
}