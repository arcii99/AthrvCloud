//FormAI DATASET v1.0 Category: QR code generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define QRCODE_SIZE 33
#define BLACK_N_WHITE "\033[1;30;47m  \033[0m"
#define WHITE_N_WHITE "\033[1;30;47m  \033[0m"

void generateQRCode(char qrCode[QRCODE_SIZE][QRCODE_SIZE]) {
    srand(time(NULL));   // Initialize random generator

    // Fill the QR code with random black (1)
    // and white (0) squares
    for(int i = 0; i < QRCODE_SIZE; i++) {
        for(int j = 0; j < QRCODE_SIZE; j++) {
            int random = rand() % 2;
            qrCode[i][j] = random ? '1' : '0';
        }
    }
}

void printQRCode(char qrCode[QRCODE_SIZE][QRCODE_SIZE]) {
    printf("\n");
    for(int i = 0; i < QRCODE_SIZE; i++) {
        for(int j = 0; j < QRCODE_SIZE; j++) {
            if(qrCode[i][j] == '1') {
                printf(BLACK_N_WHITE);
            } else {
                printf(WHITE_N_WHITE);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char qrCode[QRCODE_SIZE][QRCODE_SIZE];
    memset(qrCode, 0, sizeof(qrCode));

    generateQRCode(qrCode);
    printQRCode(qrCode);

    return 0;
}