//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t calculate_checksum(char *data, size_t size) {

    uint32_t checksum = 0xFFFFFFFF; // start with initial value

    // process the data
    for (size_t i = 0; i < size; i++) {

        checksum ^= data[i]; // xor the data byte with the current checksum

        // perform the cyclic operation for every 8 bits of data
        for (int j = 0; j < 8; j++) {

            uint32_t check_bit = checksum & 1;

            checksum >>= 1; // shift the checksum one bit to the right

            // if the leftmost bit is 1, perform the module-2 division with the polynomial
            if (check_bit) {
                checksum ^= 0xEDB88320;
            }
        }
    }

    return ~checksum; // take the bitwise complement of the final checksum
}

int main() {

    char data[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
    size_t size = sizeof(data) / sizeof(data[0]);

    uint32_t checksum = calculate_checksum(data, size);

    printf("Data: ");
    for (size_t i = 0; i < size; i++) {
        printf("%c", data[i]);
    }

    printf("\nChecksum: 0x%X\n", checksum);

    return 0; // indicate successful program termination
}