//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>

// Define the byte size for the calculation
#define BYTESIZE 8
// Define the polynomial for generating the checksum
#define POLYNOMIAL 0x1D

/**
 * Calculate the checksum of the given data
 */
unsigned char calculate_checksum(unsigned char *data, int length) {
    unsigned char checksum = 0;
    int i, j;

    for (i = 0; i < length; i++) {
        // XOR the checksum with the data byte
        checksum ^= data[i];

        for (j = 0; j < BYTESIZE; j++) {
            // If the most significant bit is set, apply the polynomial
            if (checksum & 0x80) {
                checksum = (checksum << 1) ^ POLYNOMIAL;
            } else {
                checksum <<= 1;
            }
        }
    }

    return checksum;
}

int main() {
    // Define the data
    unsigned char data[] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB};

    // Calculate the checksum
    unsigned char checksum = calculate_checksum(data, sizeof(data));

    // Print the checksum in hex format
    printf("Checksum: 0x%02X\n", checksum);

    return 0;
}