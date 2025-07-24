//FormAI DATASET v1.0 Category: QR code reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define QR_VERSION 3
#define WIDTH (QR_VERSION*4 + 17)

typedef struct {
    uint8_t data[200];
    int size;
} QRData;

void printQRData(QRData *qrData) {
    for (int row = 0; row < WIDTH; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%c", (qrData->data[row * WIDTH + col]) ? '#' : ' ');
        }
        printf("\n");
    }
}

int readQRCode(QRData *qrData, char *fileName) {
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        return -1;
    }
    memset(qrData->data, 0, sizeof(qrData->data));
    int row = 0, col = 0, c;
    while ((c = fgetc(fp)) != EOF && row < WIDTH) {
        if (col >= WIDTH) {
            col = 0;
            row++;
        }
        if (!isspace(c)) {
            qrData->data[row * WIDTH + col] = 1;
        }
        col++;
    }
    fclose(fp);
    qrData->size = row;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <qrcode file>\n", argv[0]);
        exit(1);
    }
    QRData qrData;
    if (readQRCode(&qrData, argv[1]) == -1) {
        printf("Error: Failed to read QR code file %s\n", argv[1]);
        exit(1);
    }
    printQRData(&qrData);
    return 0;
}