//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Function to compute 16-bit one's complement of sum of array elements */
uint16_t ones_complement_sum(uint8_t *data, int size) {
    uint32_t sum = 0;

    for (int i = 0; i < size; i += 2) {
        sum += (data[i] << 8) | data[i+1];
    }

    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return (uint16_t)~sum;
}

/* Function to compute 16-bit ones' complement checksum of array */
uint16_t ones_complement_checksum(uint8_t *data, int size) {
    uint32_t sum = 0;

    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return (uint16_t)~sum;
}

int main(int argc, char **argv) {
    uint8_t data[] = {0x45, 0x00, 0x00, 0x3c, 0x1c, 0x46, 0x40, 0x00, 0x40, 0x06, 0xb8, 0x9d, 0xc0, 0xa8, 0x00, 0x64, 
                      0xac, 0xd9, 0xa7, 0x17, 0x00, 0x50, 0xa5, 0x33, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x02, 0xfa, 0xf0, 
                      0x4d, 0x2f, 0x00, 0x00, 0x02, 0x04, 0x05, 0xb4, 0x01, 0x03, 0x03, 0x08, 0x01, 0x01, 0x04, 0x02};
    int size = sizeof(data) / sizeof(data[0]);

    /* Compute ones' complement sum of data array */
    uint16_t sum = ones_complement_sum(data, size);

    printf("Ones' complement sum: 0x%04x\n", sum);

    /* Compute ones' complement checksum of data array */
    uint16_t checksum = ones_complement_checksum(data, size);

    printf("Ones' complement checksum: 0x%04x\n", checksum);

    return 0;
}