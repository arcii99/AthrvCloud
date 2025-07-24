//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to calculate two's complement sum
uint16_t twos_complement_sum(uint16_t *data, size_t size) {
    uint32_t sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += data[i];
        if (sum > 0xFFFF) {
            sum = (sum & 0xFFFF) + 1;
        }
    }
    return (uint16_t) sum;
}

// Function to calculate ones' complement sum
uint16_t ones_complement_sum(uint16_t *data, size_t size) {
    uint32_t sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += data[i];
        if (sum > 0xFFFF) {
            sum = (sum & 0xFFFF) + 1;
        }
    }
    return ~(uint16_t) sum;
}

int main() {
    uint16_t data[] = {0x02, 0x04, 0x01, 0x00, 0x5A, 0x51}; // Some sample data
    size_t size = sizeof(data) / sizeof(data[0]);
    printf("Data: ");
    for (size_t i = 0; i < size; i++) {
        printf("%#04x ", data[i]);
    }
    printf("\n");

    uint16_t sum_twos = twos_complement_sum(data, size);
    printf("Two's Complement Checksum: %#04x\n", sum_twos);

    uint16_t sum_ones = ones_complement_sum(data, size);
    printf("One's Complement Checksum: %#04x\n", sum_ones);

    return 0;
}