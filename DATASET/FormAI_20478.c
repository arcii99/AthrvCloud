//FormAI DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHUNK_SIZE 100

typedef struct {
    char chunk[CHUNK_SIZE];
    int len;
} compressed_chunk_t;

void compress_data(char* input_data, int input_len, compressed_chunk_t** output_data, int* output_len) {
    // Allocate array of compressed chunks, assuming each compressed chunk is at most half the size of the input data
    int num_chunks = (input_len + CHUNK_SIZE - 1) / CHUNK_SIZE;
    *output_data = (compressed_chunk_t*) malloc(num_chunks * sizeof(compressed_chunk_t));

    // Compress each chunk
    for (int i = 0; i < num_chunks; i++) {
        compressed_chunk_t* chunk = &(*output_data)[i];

        // Copy the chunk data into the compressed chunk
        int chunk_len = CHUNK_SIZE;
        if (i == num_chunks - 1) {
            chunk_len = input_len % CHUNK_SIZE;
        }
        memcpy(chunk->chunk, input_data + i * CHUNK_SIZE, chunk_len);
        chunk->len = chunk_len;

        // Perform some fancy compression algorithm (which I made up)
        int sum = 0;
        for (int j = 0; j < chunk_len; j++) {
            sum += chunk->chunk[j];
        }
        int mean = sum / chunk_len;
        for (int j = 0; j < chunk_len; j++) {
            chunk->chunk[j] -= mean;
        }
    }

    // Set the output length to the number of compressed chunks
    *output_len = num_chunks;
}

void decompress_data(compressed_chunk_t* input_data, int input_len, char** output_data, int* output_len) {
    // Allocate output buffer assuming each compressed chunk maps to a full chunk
    *output_len = input_len * CHUNK_SIZE;
    *output_data = (char*) malloc(*output_len);

    // Decompress each chunk
    for (int i = 0; i < input_len; i++) {
        compressed_chunk_t* chunk = &input_data[i];

        // Reverse the fancy compression algorithm (which I made up)
        int sum = 0;
        for (int j = 0; j < chunk->len; j++) {
            sum += chunk->chunk[j];
        }
        int mean = sum / chunk->len;
        for (int j = 0; j < chunk->len; j++) {
            chunk->chunk[j] += mean;
        }

        // Copy the decompressed chunk data into the output buffer
        memcpy(*output_data + i * CHUNK_SIZE, chunk->chunk, chunk->len);
    }
}

int main(int argc, char** argv) {
    // Define some sample data
    char sample_data[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed quis diam in lectus varius suscipit. Proin lacinia ipsum eu pulvinar volutpat. Sed sit amet convallis justo. Cras hendrerit finibus bibendum. Donec eget dui sit amet velit pharetra elementum. Suspendisse potenti. Nullam accumsan viverra enim, quis lobortis risus vehicula eget. In a neque in diam bibendum bibendum.";


    // Compress the data
    compressed_chunk_t* compressed_data;
    int num_chunks;
    compress_data(sample_data, strlen(sample_data), &compressed_data, &num_chunks);

    // Decompress the data
    char* decompressed_data;
    int decompressed_len;
    decompress_data(compressed_data, num_chunks, &decompressed_data, &decompressed_len);

    // Check that the decompressed data matches the original data
    if (strcmp(sample_data, decompressed_data) == 0) {
        printf("Compression and decompression successful\n");
    } else {
        printf("Compression and decompression failed\n");
    }

    // Free memory
    free(compressed_data);
    free(decompressed_data);

    return 0;
}