//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define POLYNOMIAL 0xEDB88320L
#define BUFFER_SIZE 1024

uint32_t crcTable[256] = { 0 };

bool initializeCRCTable(void) {
    int32_t index, bit;
    uint32_t crc;

    for(index = 0; index < 256; index++) {
        crc = index;
        for(bit = 0; bit < 8; bit++) {
            if(crc & 1) {
                crc = (crc >> 1) ^ POLYNOMIAL;
            } else {
                crc >>= 1;
            }
        }
        crcTable[index] = crc;
    }

    return true;
}

uint32_t calculateCRC(uint8_t* buffer, uint32_t length, uint32_t crcInit) {
    uint32_t crc = crcInit;
    uint32_t index;

    for(index = 0; index < length; index++) {
        crc = crcTable[(crc ^ buffer[index]) & 0xFF] ^ (crc >> 8);
    }

    return crc;
}

int main(void) {

    if(!initializeCRCTable()) {
        printf("Failed to initialize CRC table!");
        return -1;
    }

    uint8_t buffer[BUFFER_SIZE];
    uint32_t length = BUFFER_SIZE;
    uint32_t crcInit = 0xFFFFFFFFL;
    uint32_t crc = 0;

    FILE* file;
    char* filename = "example.txt";

    if((file = fopen(filename, "rb")) == NULL) {
        printf("Failed to open file: %s", filename);
        return -1;
    }

    while((length = fread(buffer, sizeof(uint8_t), BUFFER_SIZE, file))) {

        crc = calculateCRC(buffer, length, crcInit);
        crcInit = crc;
    }

    fclose(file);
    printf("Checksum for file %s: 0x%08x", filename, crc);

    return 0;
}