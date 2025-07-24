//FormAI DATASET v1.0 Category: QR code reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t version;
    uint8_t dataLength;
    uint8_t encoding;
    uint8_t *data;
} QRCode;

void readQRCode(QRCode *code, const uint8_t *rawData) {
    code->version = rawData[0];
    code->dataLength = rawData[1];
    code->encoding = rawData[2];
    code->data = (uint8_t*)malloc(sizeof(uint8_t) * code->dataLength);
    memcpy(code->data, &rawData[3], code->dataLength);
}

void freeQRCode(QRCode *code) {
    free(code->data);
    code->data = NULL;
}

int main() {
    const uint8_t rawData[] = {3, 11, 1, 'C', 'o', 'd', 'i', 'n', 'g', ' ', 'i', 's', ' ', 'f', 'u', 'n'};
    QRCode code;

    readQRCode(&code, rawData);

    printf("QR Code Version: %u\n", code.version);
    printf("QR Code Data: %s\n", code.data);

    freeQRCode(&code);

    return 0;
}