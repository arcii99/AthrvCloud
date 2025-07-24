//FormAI DATASET v1.0 Category: QR code reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define QR_CODE_MAX_VERSION 40
#define QR_CODE_MAX_SIZE (QR_CODE_MAX_VERSION * 4 + 17)
#define QR_CODE_PAD_SIZE 4
#define QR_CODE_MAX_BIT_DATA_SIZE 2876

typedef struct QrCode {
    uint8_t version;  // QR code version number (1 ~ 40)
    uint8_t size;  // QR code size in modules (21 ~ 177)
    uint8_t ecl;  // error correction level (0 ~ 3)
    uint8_t *data;  // encoded data bits
} QrCode;

typedef struct QrCodeReader {
    char data[QR_CODE_MAX_SIZE][QR_CODE_MAX_SIZE];
    uint8_t version;
    uint8_t size;
    uint8_t ecl;
} QrCodeReader;

QrCodeReader* CreateQrCodeReader() {
    QrCodeReader *reader = (QrCodeReader*)malloc(sizeof(QrCodeReader));
    if(!reader) {
        return NULL;
    }
    memset(reader->data, 0, sizeof(char) * QR_CODE_MAX_SIZE * QR_CODE_MAX_SIZE);
    reader->version = 0;
    reader->size = 0;
    reader->ecl = 0;
    return reader;
}

void DestroyQrCodeReader(QrCodeReader *reader) {
    if(reader) {
        free(reader);
    }
}

int GetSizeFromVersion(int version) {
    return (version - 1) * 4 + 21;
}

bool DecodeQrCode(QrCodeReader *reader, const char *bit_data, int bit_len) {
    if(!reader || !bit_data || bit_len <= 0 || bit_len > QR_CODE_MAX_BIT_DATA_SIZE) {
        return false;
    }
    uint8_t *code_data = (uint8_t*)malloc(bit_len * sizeof(uint8_t));
    if(!code_data) {
        return false;
    }
    memset(code_data, 0, bit_len * sizeof(uint8_t));
    uint8_t count = 0;
    for(int i = 0; i < bit_len; i += 8) {
        uint8_t tmp = 0;
        for(int j = 0; j < 8; j++) {
            if(bit_data[i+j] == '1') {
                tmp |= 1 << (7-j);
            }
        }
        code_data[count++] = tmp;
    }
    int ecl_index = (code_data[0] & 0x03) - 1;
    reader->ecl = (ecl_index >= 0 && ecl_index <= 3) ? ecl_index : 0;
    int version_index = ((code_data[0] & 0xf0) >> 4) - 1;
    reader->version = (version_index >= 0 && version_index <= 15) ? version_index + 1 : 0;
    reader->size = GetSizeFromVersion(reader->version);
    int index = 0;
    for(int i = reader->size - 1; i >= QR_CODE_PAD_SIZE; i -= 2) {
        if(i == QR_CODE_PAD_SIZE + 1) {
            i--;
        }
        int len = QR_CODE_PAD_SIZE + (i - QR_CODE_PAD_SIZE) * 2;
        memset(reader->data[i], 0, len);
        for(int j = 0; j < len; j++) {
            reader->data[i][j] = (code_data[index >> 3] >> (7 - (index & 7))) & 1 ? '#' : '.';
            index++;
        }
    }
    free(code_data);
    return true;
}

void PrintQrCodeReader(QrCodeReader *reader) {
    if(reader && reader->size > 0 && reader->version > 0) {
        printf("QR code reader version: %d, size: %dx%d, ecl: %d, data:\n", reader->version, reader->size, reader->size, reader->ecl);
        for(int i = reader->size - 1; i >= QR_CODE_PAD_SIZE; i -= 2) {
            printf("%.*s\n", QR_CODE_PAD_SIZE + (i - QR_CODE_PAD_SIZE) * 2, reader->data[i]);
        }
    }
}

int main() {
    const char *bit_data = "01000001010110000101100100101100011010110111001001110111011001110110010001110100011011000100011001101001010111000010111101101111001110110010111000110110001110010011011010110111101101110001001010010101001101111";
    QrCodeReader *reader = CreateQrCodeReader();
    if(!reader || !DecodeQrCode(reader, bit_data, strlen(bit_data))) {
        printf("Failed to decode QR code.\n");
        DestroyQrCodeReader(reader);
        return -1;
    }
    PrintQrCodeReader(reader);
    DestroyQrCodeReader(reader);
    return 0;
}