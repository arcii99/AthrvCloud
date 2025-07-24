//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include <stdio.h>
#include <stdint.h>

/* Function to calculate 8-bit checksum of data using XOR */
uint8_t calculate_checksum(uint8_t *data, uint32_t length) {
    uint8_t checksum = 0;
    for(int i = 0; i < length; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

int main(int argc, char **argv) {

    /* Data to calculate checksum for */
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};

    /* Get length of data */
    uint32_t length = sizeof(data)/sizeof(data[0]);

    /* Calculate checksum */
    uint8_t checksum = calculate_checksum(data, length);

    /* Print the calculated checksum */
    printf("Checksum: 0x%02X\n", checksum);

    return 0;
}