//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to calculate the C checksum of a given packet
uint16_t c_checksum(uint8_t *packet, int length) {
    uint16_t crc = 0xFFFF;
    for(int i = 0; i < length; i++) {
        crc ^= (uint16_t)packet[i] << 8;
        for(int j = 0; j < 8; j++) {
            if(crc & 0x8000) {
                crc = (crc << 1) ^ 0x1021;
            }
            else {
                crc <<= 1;
            }
        }
    }
    return crc;
}

int main() {
    // Packet data
    uint8_t packet[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    int length = sizeof(packet)/sizeof(packet[0]);

    // Calculate the C checksum
    uint16_t checksum = c_checksum(packet, length);

    // Print the result
    printf("C checksum: %04X\n", checksum);

    return 0;
}