//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>
#include <stdint.h>

// Function to calculate the checksum of the given data
uint16_t calculate_checksum(const uint8_t *data, uint32_t data_len) {
    uint32_t sum = 0;
    uint16_t checksum = 0;

    // Iterate over all the bytes in the data
    for(uint32_t i=0; i<data_len; i++) {
        // Add each byte to the sum
        sum += data[i];
        // If we have overflowed the 16-bit sum, carry over the overflow to the lower 16 bits
        if(sum > 0xFFFF) {
            sum = (sum & 0xFFFF) + (sum >> 16);
        }
    }

    // Get the 1's complement of the sum and return it as the checksum
    checksum = ~(uint16_t)sum;
    return checksum;
}

int main() {
    uint8_t data[] = {0x02, 0x04, 0x06, 0x08, 0x10, 0x12, 0x14, 0x16};
    uint32_t data_len = sizeof(data);
    uint16_t checksum = calculate_checksum(data, data_len);

    printf("Data: ");
    for(uint32_t i=0; i<data_len; i++) {
        printf("%02X ", data[i]);
    }
    printf("\nChecksum: %04X", checksum);

    return 0;
}