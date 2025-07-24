//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <stdint.h>

uint16_t calculate_checksum(uint8_t *data, uint32_t length) {
    uint32_t sum = 0;

    // Sum up all 16-bit values from the input data
    while (length > 1) {
        sum += *data++;
        sum += (*data++) << 8;
        length -= 2;
    }

    // Add in any odd byte at the end
    if (length > 0) {
        sum += *data;
    }

    // Add in the carry from any 16-bit overflows
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    // Final 1's complement calculation
    return (uint16_t)(~sum);
}

int main() {
    // Get input data from the user
    uint8_t data[50];
    printf("Enter up to 50 bytes of data to calculate checksum: ");
    fgets(data, 50, stdin);

    // Call the checksum calculation function
    uint16_t checksum = calculate_checksum(data, strlen(data));

    // Print out the result
    printf("Checksum is: 0x%04X\n", checksum);

    return 0;
}