//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Calculate the 8-bit checksum of a given buffer
uint8_t calculate_checksum(uint8_t *buffer, size_t size) {
    uint8_t checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += buffer[i];
    }
    return ~checksum + 1;
}

int main() {
    uint8_t buffer[] = {0xAA, 0x55, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
    size_t size = sizeof(buffer)/sizeof(buffer[0]);

    // Calculate the checksum
    uint8_t checksum = calculate_checksum(buffer, size);

    // Print the checksum
    printf("Checksum: 0x%X\n", checksum);

    return 0;
}