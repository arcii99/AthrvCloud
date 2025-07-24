//FormAI DATASET v1.0 Category: QR code reader ; Style: scientific
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 500

uint8_t readQRCode(uint8_t qrCode[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE], uint32_t size) {
    uint8_t data[size*size];
    uint32_t row, col;
    bool endFound = false;
    uint8_t i = 0;
    uint8_t bitCount, bitMask;

    row = 0;
    col = 0;
    bitCount = 0;
    bitMask = 0x01;

    while(!endFound && row < size) {
        data[i] = (qrCode[row][col] & bitMask) != 0 ? 1 : 0;
        i++;

        if((qrCode[row][col] & 0x08) != 0) {
            endFound = true;
        }

        if(bitCount == 7) {
            bitCount = 0;
            bitMask = 0x01;
            col++;

            if(col == size) {
                col = 0;
                row++;
            }
        } else {
            bitCount++;
            bitMask <<= 1;
        }
    }

    return i;
}

int main() {
    uint8_t qrCode[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE] = {0};
    uint32_t size = 0;
    // code to read QR code and fill qrCode and size variable
    uint8_t data[MAX_QR_CODE_SIZE * MAX_QR_CODE_SIZE] = {0};
    uint8_t dataLen;

    dataLen = readQRCode(qrCode, size);
    printf("QR code read successfully with length: %u", dataLen);

    return 0;
}