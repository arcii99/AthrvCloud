//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCKSIZE 1024

// Calculate the checksum of a given file
uint16_t calculateChecksum(FILE* file) {
    uint16_t checksum = 0;
    uint8_t buffer[BLOCKSIZE];

    // Read the file block by block and calculate the sum of bytes
    while (!feof(file)) {
        size_t bytesRead = fread(buffer, sizeof(uint8_t), BLOCKSIZE, file);

        for (size_t i = 0; i < bytesRead; i++) {
            checksum += buffer[i];
        }
    }

    // Calculate the final checksum as the ones complement of the sum
    checksum = ~checksum;

    return checksum;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filename = argv[1];

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file \"%s\"\n", filename);
        return EXIT_FAILURE;
    }

    uint16_t checksum = calculateChecksum(file);
    printf("Checksum of \"%s\": %04X\n", filename, checksum);

    fclose(file);
    return EXIT_SUCCESS;
}