//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <stdint.h>

uint16_t calc_checksum(uint8_t *data, uint32_t length)
{
    uint32_t checksum = 0;
    while (length > 1) {
        checksum += *(data++) << 8;
        checksum += *(data++);
        length -= 2;
    }
    if (length) {
        checksum += *(data++) << 8;
    }
    while (checksum >> 16) {
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
    }
    return ~checksum;
}

int main()
{
    uint8_t data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    uint32_t length = sizeof(data);
    uint16_t checksum = calc_checksum(data, length);
    printf("Checksum: 0x%04X\n", checksum);
    return 0;
}