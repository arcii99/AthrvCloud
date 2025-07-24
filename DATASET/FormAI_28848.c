//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: safe
#include <stdio.h>
#include <stdint.h>

// Function to calculate the checksum of an array of bytes
uint16_t checksum_calculator(const uint8_t *buf, size_t size)
{
    uint32_t sum = 0;

    // Add the bytes in the buffer to the sum variable
    while (size > 1) {
        sum += *buf++;
        size -= 2;
    }

    // If the size of the buffer is odd, add the last byte to the sum
    if (size) {
        sum += *(uint8_t *)buf;
    }

    // Fold the sum into a 16-bit integer
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    // Take the one's complement of the sum
    return (uint16_t)(~sum);
}

int main()
{
    uint8_t buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05};

    // Calculate the checksum of the buffer
    uint16_t checksum = checksum_calculator(buffer, sizeof(buffer));

    // Print the checksum value
    printf("Checksum: 0x%04X\n", checksum);

    return 0;
}