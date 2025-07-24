//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>
#include <stdint.h>

/**
 * Function to perform one's complement checksum on data
 *
 * @param data - input data buffer
 * @param length - length of the data buffer
 *
 * @return - calculated checksum
 */
uint16_t ones_complement_checksum(const uint8_t *data, size_t length) {
    uint32_t sum = 0;

    for (size_t i = 0; i < length; i += 2) {
        uint16_t word = 0;
        if (i + 1 < length) {
            word = ((uint16_t)data[i] << 8) | (uint16_t)data[i + 1];
        } else {
            word = (uint16_t)data[i];
        }
        sum += (uint32_t)word;
    }

    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return (uint16_t)~sum;
}

int main() {
    uint8_t data[] = {0x45, 0x00, 0x00, 0x3c, 0x1c, 0x46, 0x40, 0x00, 0x40, 0x06, 0x76, 0xb7, 0xc0, 0xa8, 0x01, 0x01, 0xc0, 0xa8, 0x01, 0xc7};
    size_t length = sizeof(data) / sizeof(data[0]);

    uint16_t checksum = ones_complement_checksum(data, length);
    printf("Checksum: 0x%04x\n", checksum);

    return 0;
}