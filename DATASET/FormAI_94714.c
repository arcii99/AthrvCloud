//FormAI DATASET v1.0 Category: QR code generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QR_CODE_SIZE 6 // The size of a QR code is set to 6

void generateQRCode(char qrCode[QR_CODE_SIZE][QR_CODE_SIZE]) {
    int i, j;
    for(i = 0; i < QR_CODE_SIZE; i++) {
        for(j = 0; j < QR_CODE_SIZE; j++) {
            if(i % 2 == 0) {
                qrCode[i][j] = (j % 2 == 0) ? '#' : ' ';
            } else {
                qrCode[i][j] = (j % 2 == 0) ? ' ' : '#';
            }
        }
    }
}

void printQRCode(char qrCode[QR_CODE_SIZE][QR_CODE_SIZE]) {
    int i, j;
    for(i = 0; i < QR_CODE_SIZE; i++) {
        for(j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c", qrCode[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char qrCode[QR_CODE_SIZE][QR_CODE_SIZE];
    generateQRCode(qrCode);
    printQRCode(qrCode);
    return 0;
}