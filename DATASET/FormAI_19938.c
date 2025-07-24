//FormAI DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_CODE_SIZE 21

// Helper function to convert a binary number to a hexadecimal character
char binaryToHex(char *binary) {
    int decimal = 0;
    for (int i = 0; i < 4; i++) {
        if (binary[i] == '1') {
            decimal += 1 << (3 - i);
        }
    }
    if (decimal < 10) {
        return decimal + '0';
    } else {
        return decimal - 10 + 'A';
    }
}

// Generates a unique QR code from the inputted data
void generateQRCode(char *data, char *qrCode) {
    int dataLength = strlen(data);
    if (dataLength > QR_CODE_SIZE - 1) {
        printf("Error: Data too long for QR code\n");
        return;
    }
    char binaryData[QR_CODE_SIZE * 8 + 1];
    int binaryDataIndex = 0;
    // Add mode indicator for alphanumeric data (0010)
    binaryData[binaryDataIndex++] = '0';
    binaryData[binaryDataIndex++] = '0';
    binaryData[binaryDataIndex++] = '1';
    binaryData[binaryDataIndex++] = '0';
    // Add character count indicator
    char characterCount[3];
    sprintf(characterCount, "%02d", dataLength);
    for (int i = 0; i < 8; i++) {
        binaryData[binaryDataIndex++] = (characterCount[0] & (1 << (7 - i))) ? '1' : '0';
    }
    for (int i = 0; i < 8; i++) {
        binaryData[binaryDataIndex++] = (characterCount[1] & (1 << (7 - i))) ? '1' : '0';
    }
    // Add data
    for (int i = 0; i < dataLength; i++) {
        if (i % 2 == 0) {
            // Encode two characters as 11-bit code
            char bigram[3] = {data[i], data[i+1], '\0'};
            int bigramValue = 45 * (int)(bigram[0] - '0') + (int)(bigram[1] - '0');
            for (int j = 0; j < 11; j++) {
                binaryData[binaryDataIndex++] = (bigramValue & (1 << (10 - j))) ? '1' : '0';
            }
        }
    }
    // Add padding
    while (binaryDataIndex < QR_CODE_SIZE * 8) {
        binaryData[binaryDataIndex++] = '0';
    }
    // Add terminator
    binaryData[binaryDataIndex++] = '0';
    binaryData[binaryDataIndex++] = '0';
    binaryData[binaryDataIndex++] = '0';
    binaryData[binaryDataIndex++] = '0';
    binaryData[binaryDataIndex] = '\0';
    // Convert binary data to hexadecimal QR code
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        char binaryByte[5];
        strncpy(binaryByte, binaryData + i * 4, 4);
        binaryByte[4] = '\0';
        qrCode[i] = binaryToHex(binaryByte);
    }
}

int main() {
    char data[] = "Hello, world!";
    char qrCode[QR_CODE_SIZE + 1];
    generateQRCode(data, qrCode);
    printf("QR code for \"%s\":\n", data);
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        printf("%c ", qrCode[i]);
    }
    printf("\n");
    return 0;
}