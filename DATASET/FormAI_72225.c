//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdint.h>

uint8_t rol_byte(uint8_t byte, int bits) {
    return (byte << bits) | (byte >> (8 - bits));
}

uint16_t checksum(const uint8_t *data, size_t len) {
    uint32_t sum = 0;

    while (len > 1) {
        uint16_t tmp = (data[0] << 8) | data[1];
        sum += tmp;
        data += 2;
        len -= 2;
    }
    if (len) {
        sum += rol_byte(data[0], 8);
    }

    while (sum >> 16) {
        sum = (sum & 0xffff) + (sum >> 16);
    }

    return ~sum;
}

int main() {
    uint8_t data[] = "Hello, world!";
    size_t len = sizeof(data) - 1;
    uint16_t my_checksum = checksum(data, len);

    printf("The checksum of \"%s\" is 0x%04x.\n", data, my_checksum);

    return 0;
}