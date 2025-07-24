//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef uint16_t checksum_t;

/* Function prototypes */
checksum_t calculate_checksum(uint8_t *data, size_t data_len);
checksum_t update_checksum(checksum_t current_checksum, uint8_t *data, size_t data_len);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./checksum <input_file>\n");
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file!\n");
        exit(EXIT_FAILURE);
    }

    uint8_t buffer[BUFFER_SIZE];
    checksum_t current_checksum = 0;

    while (!feof(input_file)) {
        size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file);
        current_checksum = update_checksum(current_checksum, buffer, bytes_read);
    }

    fclose(input_file);

    printf("Calculated checksum: %04X\n", current_checksum);

    return 0;
}

/**
 * Calculates the checksum for the given data.
 */
checksum_t calculate_checksum(uint8_t *data, size_t data_len) {
    checksum_t sum = 0;

    for (size_t i = 0; i < data_len; i++) {
        sum += data[i];
    }

    return ~sum;
}

/**
 * Updates the current checksum with the given data.
 */
checksum_t update_checksum(checksum_t current_checksum, uint8_t *data, size_t data_len) {
    checksum_t sum = current_checksum;

    for (size_t i = 0; i < data_len; i++) {
        sum += data[i];
    }

    // Handle overflow
    if (sum > 0xFFFF) {
        sum = (sum & 0xFFFF) + 1;
    }

    return sum;
}