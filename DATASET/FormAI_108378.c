//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// This function calculates the checksum of a given data block
uint16_t calculate_checksum(unsigned char *data, int length) {
    uint32_t sum = 0;
    
    // Loop through the data block
    for (int i = 0; i < length; i+=2) {
        uint16_t word = data[i] << 8;
        if (i+1 < length) {
            word |= data[i+1];
        }
        sum += word;
    }
    
    // Fold sum to 16 bits
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    
    // Take one's complement of sum
    uint16_t checksum = ~(uint16_t)sum;
    
    return checksum;
}

int main() {
    // Sample data block
    unsigned char data[] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};
    int length = sizeof(data) / sizeof(data[0]);
    
    // Calculate checksum of data block
    uint16_t checksum = calculate_checksum(data, length);
    
    // Print original data block
    printf("Original data block: ");
    for (int i = 0; i < length; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
    
    // Print checksum of data block
    printf("Checksum: %04X\n", checksum);
    
    return 0;
}