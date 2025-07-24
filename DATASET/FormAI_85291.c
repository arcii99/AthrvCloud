//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdint.h>

// Function to calculate the checksum of a buffer using 16-bit addition algorithm
uint16_t calculate_checksum(uint8_t *buffer, uint32_t length) {
    uint16_t checksum = 0;
    uint16_t word;

    // Iterate over each 16-bit word in the buffer
    for (uint32_t i = 0; i < length; i += 2) {
        // Convert 2 8-bit characters to a 16-bit word in little endian byte order
        word = (buffer[i+1] << 8) | buffer[i];

        // Add the word to the checksum
        checksum += word;

        // If the checksum overflows the 16-bit variable, wrap around to zero
        if (checksum > 0xFFFF) {
            checksum -= 0xFFFF;
        }
    }

    // Flip all the bits to get the final checksum value
    checksum = ~checksum;

    // Return the calculated checksum
    return checksum;
}

int main() {
    // Create a buffer with some data
    uint8_t buffer[10];
    buffer[0] = 0x01;
    buffer[1] = 0x02;
    buffer[2] = 0x03;
    buffer[3] = 0x04;
    buffer[4] = 0x05;
    buffer[5] = 0x06;
    buffer[6] = 0x07;
    buffer[7] = 0x08;
    buffer[8] = 0x09;
    buffer[9] = 0x0A;

    // Calculate the checksum of the buffer
    uint16_t checksum = calculate_checksum(buffer, 10);

    // Print the checksum in hexadecimal format
    printf("Checksum: 0x%04X\n", checksum);

    return 0;
}