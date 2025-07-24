//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#define POLY 0xEDB88320
#define BUFFER_SIZE 1024

void crc32init(uint32_t *table);
uint32_t crc32(uint32_t *table, unsigned char *buf, size_t len);

int main() {
    uint32_t crcTable[256];
    crc32init(crcTable);

    char fileName[100];
    printf("Enter filename: ");
    scanf("%s",fileName);
    FILE *file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    uint32_t crc = 0xFFFFFFFF;

    // Read file buffer and calculate CRC checksum
    while ((bytesRead = fread(buffer, 1, sizeof buffer, file)) > 0) {
        crc = crc32(crcTable, buffer, bytesRead) ^ crc;
    }

    crc = crc ^ 0xFFFFFFFF;
    printf("Calculated CRC32 checksum: %08X\n", crc);

    fclose(file);
    return 0;
}

// Generate CRC32 lookup table
void crc32init(uint32_t *table) {
    uint32_t c, i, j;
    for (i = 0; i < 256; i++) {
        c = i;
        for (j = 0; j < 8; j++) {
            c = (c & 1) ? POLY ^ (c >> 1) : c >> 1;
        }
        table[i] = c;
    }
}

// Calculate CRC32 checksum for input buffer
uint32_t crc32(uint32_t *table, unsigned char *buf, size_t len) {
    uint32_t c = 0;
    size_t i;
    for (i = 0; i < len; i++) {
        c = table[(c ^ buf[i]) & 0xFF] ^ (c >> 8);
    }
    return c;
}