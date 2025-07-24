//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: calm
/*
 * C Checksum Calculator
 *
 * This program calculates the checksum of an input file using the CRC-32 algorithm.
 * The CRC-32 algorithm generates a 32-bit value that is used to check the integrity of data.
 *
 * Author: John Doe
 *
 * Usage:
 *
 * To compile the program, run the command:
 * gcc -o checksum checksum.c
 *
 * To calculate the checksum of the input file, run the command:
 * ./checksum input_file
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define POLYNOMIAL  0xEDB88320L  /* CRC-32 polynomial */

/* Table of values for fast computation of CRC-32 */
uint32_t crc_table[256];

/* Initialize the table of values for fast computation of CRC-32 */
void crc_init() {
    uint32_t crc, i, j;

    for (i = 0; i < 256; i++) {
        crc = i;

        for (j = 0; j < 8; j++) {
            if (crc & 1)
                crc = (crc >> 1) ^ POLYNOMIAL;
            else
                crc = crc >> 1;
        }

        crc_table[i] = crc;
    }
}

/* Compute the CRC-32 checksum of a block of data of a given size */
uint32_t crc_calculate(uint8_t *data, size_t size) {
    uint32_t crc = 0xFFFFFFFF;
    size_t i;

    for (i = 0; i < size; i++)
        crc = (crc >> 8) ^ crc_table[(crc & 0xFF) ^ data[i]];

    return crc ^ 0xFFFFFFFF;
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    uint8_t *buffer;
    size_t size;
    uint32_t checksum;

    /* Initialize the table of values for fast computation of CRC-32 */
    crc_init();

    /* Open the input file */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Calculate the size of the input file */
    fseek(input_file, 0L, SEEK_END);
    size = ftell(input_file);
    rewind(input_file);

    /* Allocate memory for the buffer */
    buffer = (uint8_t *)malloc(size);
    if (!buffer) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    /* Read the input file into the buffer */
    if (fread(buffer, size, 1, input_file) != 1) {
        fprintf(stderr, "Error reading file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Compute the CRC-32 checksum of the buffer */
    checksum = crc_calculate(buffer, size);

    /* Print the checksum */
    printf("Checksum: %08X\n", checksum);

    /* Clean up */
    free(buffer);
    fclose(input_file);

    return 0;
}