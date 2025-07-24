//FormAI DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program implements a unique compression algorithm that combines both lossless and lossy techniques
 * to efficiently compress data. The algorithm works by first applying a lossy compression technique to remove
 * redundant data, then applying a lossless technique to compress the remaining data even further.
 *
 * The lossy technique used in this program is called delta encoding, which involves subtracting each data
 * item from its predecessor. The resulting numbers are then stored as 8-bit integers, effectively reducing
 * the number of bits required to represent the data.
 *
 * The lossless technique used in this program is called run-length encoding, which involves counting the
 * number of consecutive occurrences of each data item and storing this count as a single byte.
 */

#define MAX_DATA_SIZE 10000

void compress_data(char* data, int data_len, char* compressed_data, int* compressed_len) {
    // Allocate memory for the delta-encoded data
    char* delta_data = (char*) malloc(data_len * sizeof(char));
    if (delta_data == NULL) {
        printf("Failed to allocate memory for delta-encoded data\n");
        exit(1);
    }

    // Apply delta encoding to the original data
    delta_data[0] = data[0];
    for (int i = 1; i < data_len; i++) {
        delta_data[i] = data[i] - data[i-1];
    }

    // Allocate memory for the run-length encoded data
    char* run_length_data = (char*) malloc(data_len * sizeof(char));
    if (run_length_data == NULL) {
        printf("Failed to allocate memory for run-length encoded data\n");
        exit(1);
    }

    // Apply run-length encoding to the delta-encoded data
    int run_length = 1;
    int j = 0;
    for (int i = 1; i < data_len; i++) {
        if (delta_data[i] == delta_data[i-1]) {
            run_length++;
        } else {
            run_length_data[j] = delta_data[i-1];
            run_length_data[j+1] = run_length;
            j += 2;
            run_length = 1;
        }
    }
    // Account for the last run
    run_length_data[j] = delta_data[data_len-1];
    run_length_data[j+1] = run_length;
    j += 2;

    // Allocate memory for the final compressed data
    char* final_data = (char*) malloc(j * sizeof(char));
    if (final_data == NULL) {
        printf("Failed to allocate memory for final compressed data\n");
        exit(1);
    }

    // Copy the run-length encoded data to the final compressed data buffer
    memcpy(final_data, run_length_data, j);

    // Update the compressed length and return the final compressed data
    *compressed_len = j;
    memcpy(compressed_data, final_data, *compressed_len);

    // Free dynamically allocated memory
    free(delta_data);
    free(run_length_data);
    free(final_data);
}

int main() {
    // Generate some sample data to compress
    char data[MAX_DATA_SIZE];
    for (int i = 0; i < MAX_DATA_SIZE; i++) {
        data[i] = rand() % 256;
    }
    int data_len = MAX_DATA_SIZE;

    // Allocate memory for the compressed data
    char* compressed_data = (char*) malloc(data_len * sizeof(char));
    if (compressed_data == NULL) {
        printf("Failed to allocate memory for compressed data\n");
        exit(1);
    }

    // Compress the data using our unique algorithm
    int compressed_len;
    compress_data(data, data_len, compressed_data, &compressed_len);

    // Print the original and compressed data sizes
    printf("Original data size: %d bytes\n", data_len);
    printf("Compressed data size: %d bytes\n", compressed_len);

    // Free dynamically allocated memory
    free(compressed_data);

    return 0;
}