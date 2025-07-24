//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>
#include <stdint.h>

/* Functions to calculate checksum */
uint16_t checksum(uint16_t *ptr, int nbytes);

int main() {
    uint16_t data[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8}; /* Sample data */
    int total_bytes = sizeof(data); /* Calculate the total number of bytes */
    uint16_t sum = checksum(data, total_bytes);

    printf("Checksum Total: 0x%x\n", sum);
    return 0;
}

/* Checksum calculation implementation */
uint16_t checksum(uint16_t *ptr, int nbytes) {
    uint32_t sum;
    uint16_t oddbyte;
    uint16_t answer;

    sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1) {
        oddbyte = 0;
        *((uint8_t*) &oddbyte) = *(uint8_t*)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = ~sum;

    return answer;
}