//FormAI DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 2048

// Run-length encoding algorithm
void rle_encode(const uint8_t *input, uint8_t *output, size_t input_size, size_t *encoded_size) {
    uint8_t count = 1;
    uint8_t current = input[0];
    size_t output_index = 0;

    for (int i = 1; i <= input_size; i++) {
        if (input[i] != current || count == 255) {
            output[output_index++] = count;
            output[output_index++] = current;
            count = 1;
            current = input[i];
        }
        else {
            count++;
        }
    }

    *encoded_size = output_index;
}

// Run-length decoding algorithm
void rle_decode(const uint8_t *input, uint8_t *output, size_t input_size, size_t *decoded_size) {
    uint8_t count = 0;
    size_t output_index = 0;

    for (int i = 0; i < input_size; i += 2) {
        count = input[i];
        for (int j = 0; j < count; j++) {
            output[output_index++] = input[i+1];
        }
    }

    *decoded_size = output_index;
}

int main() {
    char input_buffer[MAX_INPUT_SIZE];
    uint8_t input[MAX_INPUT_SIZE];
    uint8_t encoded[MAX_OUTPUT_SIZE];
    uint8_t decoded[MAX_INPUT_SIZE];
    size_t input_size, encoded_size, decoded_size;

    // Read input from user
    printf("Enter string to encode: ");
    fgets(input_buffer, MAX_INPUT_SIZE, stdin);
    input_size = strlen(input_buffer) - 1;
    memcpy(input, input_buffer, input_size);

    // Encode using RLE
    rle_encode(input, encoded, input_size, &encoded_size);

    printf("Encoded: ");
    for (int i = 0; i < encoded_size; i++) {
        printf("%d,", encoded[i]);
    }
    printf("\n");

    // Decode using RLE
    rle_decode(encoded, decoded, encoded_size, &decoded_size);

    printf("Decoded: ");
    for (int i = 0; i < decoded_size; i++) {
        printf("%c", decoded[i]);
    }
    printf("\n");

    return 0;
}