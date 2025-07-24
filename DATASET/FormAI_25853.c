//FormAI DATASET v1.0 Category: Compression algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPRESSION_RATIO 20
#define BLOCK_SIZE 1024

unsigned char* compress_data(const unsigned char *data, const size_t length, size_t *compressed_size){
    int i,j;
    unsigned char *compressed_data = (unsigned char*) calloc((length/MAX_COMPRESSION_RATIO) + 1, sizeof(unsigned char));

    if (compressed_data == NULL) {
        exit(EXIT_FAILURE);
    }

    i = 0;
    j = 0;
    while (i < length) {
        int count = 1;
        // Look for repetitions in blocks
        while ((i + count) < length &&
            (count < MAX_COMPRESSION_RATIO) &&
            (memcmp(&data[i], &data[i+count], 1) == 0)) {
                count++;
            }

        // Check for block repetition
        if (count > 3) {
            // Block repetition found, write repetition count byte
            compressed_data[j++] = count;

            // Write block byte
            compressed_data[j++] = data[i];

            // Step to next block
            i += count;
        } else {
            // No block repetition found, write single byte
            compressed_data[j++] = 0;
            compressed_data[j++] = data[i];

            // Step to next byte
            i++;
        }
    }

    // Set the compressed size
    *compressed_size = j;

    // Return the compressed data
    return compressed_data;
}

unsigned char* decompress_data(const unsigned char *data, const size_t length, size_t *decompressed_size){
    int i,j;
    unsigned char *decompressed_data = (unsigned char*) calloc(length * MAX_COMPRESSION_RATIO, sizeof(unsigned char));

    if (decompressed_data == NULL) {
        exit(EXIT_FAILURE);
    }

    i = 0;
    j = 0;
    while (i < length) {
        // Check for block repetition count
        if (data[i] > 0) {
            // Block repetition found, write it several times
            int count = data[i];
            unsigned char ch = data[i+1];

            for (int k = 0; k < count; k++) {
                decompressed_data[j++] = ch;
            }

            // Step to next block
            i += 2;
        } else {
            // No block repetition found, write single byte
            decompressed_data[j++] = data[i+1];

            // Step to next byte
            i += 2;
        }
    }

    // Set the decompressed size
    *decompressed_size = j;

    // Return the decompressed data
    return decompressed_data;
}

int main() {
    unsigned char *original_data = "Hello, this is a test of my compression algorithm. Will it work?";
    size_t original_size = strlen(original_data);
    size_t compressed_size = 0;
    size_t decompressed_size = 0;

    printf("Original size: %d\n", original_size);

    // Compress the data
    unsigned char *compressed_data = compress_data(original_data, original_size, &compressed_size);

    printf("Compressed size: %d\n", compressed_size);

    // Decompress the data
    unsigned char *decompressed_data = decompress_data(compressed_data, compressed_size, &decompressed_size);

    printf("Decompressed size: %d\n", decompressed_size);

    // Check that the decompressed data is the same as the original data
    if (memcmp(original_data, decompressed_data, original_size) == 0) {
        printf("Data successfully compressed and decompressed.\n");
    } else {
        printf("Error: unable to compress and decompress data.\n");
    }

    free(compressed_data);
    free(decompressed_data);

    return 0;
}