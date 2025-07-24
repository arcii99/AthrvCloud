//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_SIZE 21
#define WHITE_SPACE "\u2588"

void generateQRCode(char QRCode[QR_SIZE][QR_SIZE]);
void printQRCode(char QRCode[QR_SIZE][QR_SIZE]);

int main() {
    char QRCode[QR_SIZE][QR_SIZE];
    
    generateQRCode(QRCode);
    printQRCode(QRCode);
    
    return 0;
}

void generateQRCode(char QRCode[QR_SIZE][QR_SIZE]) {
    srand(time(NULL));
    
    int i, j;
    
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            QRCode[i][j] = rand() % 2 == 0 ? '1' : '0';
        }
    }
}

void printQRCode(char QRCode[QR_SIZE][QR_SIZE]) {
    int i, j;
    
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            printf("%s", QRCode[i][j] == '0' ? "  " : WHITE_SPACE);
        }
        printf("\n");
    }
}