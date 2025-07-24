//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Linus Torvalds
/*
 * Linux-style Checksum Calculator
 *
 * This program calculates the checksum of a given file. It uses the algorithm
 * described by Linus Torvalds in his kernel source code. The checksum is
 * calculated using a 32-bit unsigned integer.
 *
 * Author: Your Name
 */

#include <stdio.h>
#include <stdint.h>

#define BUF_SIZE 1024

uint32_t calculate_checksum(FILE *file);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", argv[1]);
        return 1;
    }

    uint32_t checksum = calculate_checksum(file);

    printf("Checksum: 0x%08x\n", checksum);

    fclose(file);

    return 0;
}

uint32_t calculate_checksum(FILE *file)
{
    uint32_t checksum = 0;
    uint8_t buf[BUF_SIZE];
    size_t buflen;

    while ((buflen = fread(buf, 1, BUF_SIZE, file)) > 0) {
        uint32_t i;

        for (i = 0; i < buflen; i++)
            checksum = (checksum >> 1) + ((checksum & 1) << 31) + buf[i];
    }

    return checksum;
}