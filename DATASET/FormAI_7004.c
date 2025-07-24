//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: satisfied
#include <stdio.h>
#include <stdint.h>

// Calculate the C Checksum of an array of bytes
uint8_t calculateChecksum(uint8_t* data, int length) {
    uint8_t checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum += data[i];
    }
    checksum = (~checksum) + 1;
    return checksum;
}

int main() {
    uint8_t data[] = {0x02, 0x08, 0x12, 0x20, 0x43, 0x58};
    int length = 6;
    uint8_t checksum = calculateChecksum(data, length);
    printf("C Checksum: 0x%02X\n", checksum);
    return 0;
}