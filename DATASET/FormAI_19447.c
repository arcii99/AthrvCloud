//FormAI DATASET v1.0 Category: QR code reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 1000

bool isValidQRCode(char* qrCode) {
    int len = strlen(qrCode);

    if(len < 21 || len > 24) {
        return false;
    }

    if(strncmp(qrCode, "QR", 2) != 0) {
        return false;
    }

    for(int i = 0; i < len; i++) {
        if(qrCode[i] != '0' && qrCode[i] != '1') {
            return false;
        }
    }

    return true;
}

void decodeQRCode(char* qrCode) {
    int dataStartIndex = 2;
    char dataBitBuffer[MAX_QR_CODE_LENGTH] = "";
    int dataBitBufferIndex = 0;

    //Extract data bits from the QR code
    for(int i = dataStartIndex; i < strlen(qrCode); i += 2) {
        char oneByte[3] = "";
        strncpy(oneByte, &qrCode[i], 2);
        int value = strtol(oneByte, NULL, 2);

        sprintf(oneByte, "%02x", value); // Convert to hex string
        strcat(dataBitBuffer, oneByte);
        dataBitBufferIndex += 2;
    }

    // Remove padding bytes
    while (dataBitBufferIndex % 8 != 0) {
        dataBitBuffer[--dataBitBufferIndex] = '\0';
    }

    int dataByteCount = dataBitBufferIndex / 8;
    unsigned char dataBytes[dataByteCount];

    //Convert bits to bytes
    for(int i = 0; i < dataByteCount; i++) {
        dataBytes[i] = strtol(&dataBitBuffer[i * 8], NULL, 2);
    }

    printf("Decoded data: ");
    for(int i = 0; i < dataByteCount; i++) {
        printf("%c", dataBytes[i]);
    }
    printf("\n");
}

int main() {
    //Sample QR code to decode
    char* qrCode = "QR0010101111000010101101001101111010100110111001001110110111101011110101001101110010011101101111010111101010011011100100111011011111010111101001101110010011101110101111010100110111001001110110111101011110101001101110010011101101111010111101001101110010011101110101111010100110111001001110110111101011110101001101110010011101101111010111101001101110010011101110101111010100110111001001110110111101011110101001101110010011101101111010111101001101110010";

    if(isValidQRCode(qrCode)) {
        printf("Valid QR Code.\n");
        decodeQRCode(qrCode);
    }
    else {
        printf("Invalid QR Code.\n");
    }

    return 0;
}