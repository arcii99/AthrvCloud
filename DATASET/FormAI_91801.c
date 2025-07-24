//FormAI DATASET v1.0 Category: QR code generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_CODE_SIZE 21

void generateQRCode(char *qrCode);
void printQRCode(char *qrCode);

int main() {
    char qrCode[QR_CODE_SIZE + 1];

    srand(time(NULL));
    generateQRCode(qrCode);

    printf("Your unique QR code is:\n");
    printQRCode(qrCode);

    return 0;
}

void generateQRCode(char *qrCode) {
    int i;

    for(i = 0; i < QR_CODE_SIZE; i++) {
        qrCode[i] = (rand() % 10) + '0';
    }

    qrCode[QR_CODE_SIZE] = '\0';
}

void printQRCode(char *qrCode) {
    int i;

    for(i = 0; i < QR_CODE_SIZE; i++) {
        printf("%c ", qrCode[i]);
    }

    printf("\n");
}