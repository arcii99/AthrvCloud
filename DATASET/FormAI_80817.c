//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: random
#include <stdio.h>
#include <stdint.h>

// function to calculate the checksum
uint16_t calculateChecksum(uint8_t *data, int len) {
    uint32_t sum = 0;
    uint16_t *ptr = (uint16_t*)data;

    // loop through the data in 16-bit chunks
    for (int i = 0; i < len/2; i++) {
        sum += ptr[i];
    }

    // if len is odd, add the last byte
    if (len % 2 != 0) {
        sum += (uint32_t)data[len-1];
    }

    // wrap the sum if it overflows 16 bits
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    // return the one's complement of the sum
    return (uint16_t)(~sum);
}

int main() {
    uint8_t data[] = {0x04, 0x06, 0x00, 0x00, 0x00, 0x05, 0x00, 0x77};

    // calculate the checksum
    uint16_t checksum = calculateChecksum(data, sizeof(data));

    // print the data and checksum in hex
    printf("Data: ");
    for (int i = 0; i < sizeof(data); i++) {
        printf("%02X ", data[i]);
    }
    printf("\nChecksum: %04X", checksum);

    return 0;
}