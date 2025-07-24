//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

/*** Constants ***/
#define BLOCK_SIZE 64
#define OUTPUT_SIZE 32

/*** Macros ***/
#define LEFT_ROTATE(word, bits) (((word) << (bits)) | ((word) >> (32 - (bits))))

/*** Function Prototypes ***/
void compute_hash(uint8_t *message, uint64_t message_size, uint8_t hash[OUTPUT_SIZE]);

/*** Main ***/
int main(void) {
    // Test message
    char *message = "Hello, world!";
    size_t message_size = strlen(message);

    // Compute hash
    uint8_t hash[OUTPUT_SIZE];
    compute_hash((uint8_t *) message, message_size, hash);

    // Print hash as hexadecimal string
    printf("Hash: ");
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}

/*** Function Implementations ***/
void compute_hash(uint8_t *message, uint64_t message_size, uint8_t hash[OUTPUT_SIZE]) {
    // Initialization vectors
    uint32_t h0 = 0x6a09e667;
    uint32_t h1 = 0xbb67ae85;
    uint32_t h2 = 0x3c6ef372;
    uint32_t h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f;
    uint32_t h5 = 0x9b05688c;
    uint32_t h6 = 0x1f83d9ab;
    uint32_t h7 = 0x5be0cd19;

    // Pre-processing
    uint64_t original_message_size_bits = message_size * 8; // Number of bits in original message
    uint64_t new_message_size_bits;
    uint64_t padding_size;
    if (message_size % BLOCK_SIZE < 56) {
        padding_size = 56 - (message_size % BLOCK_SIZE);
    } else {
        padding_size = 120 - (message_size % BLOCK_SIZE);
    }
    new_message_size_bits = original_message_size_bits + padding_size + 8;
    uint8_t *padded_message = calloc((size_t) new_message_size_bits / 8, 1);
    if (padded_message == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    memcpy(padded_message, message, message_size);
    padded_message[message_size] = 0x80;
    for (uint64_t i = 0; i < padding_size / 8; i++) {
        padded_message[message_size + 1 + i] = 0x00;
    }
    padded_message[(size_t) (new_message_size_bits / 8) - 1] = (uint8_t) (original_message_size_bits & 0xff);
    padded_message[(size_t) (new_message_size_bits / 8) - 2] = (uint8_t) ((original_message_size_bits >> 8) & 0xff);
    padded_message[(size_t) (new_message_size_bits / 8) - 3] = (uint8_t) ((original_message_size_bits >> 16) & 0xff);
    padded_message[(size_t) (new_message_size_bits / 8) - 4] = (uint8_t) ((original_message_size_bits >> 24) & 0xff);
    padded_message[(size_t) (new_message_size_bits / 8) - 5] = (uint8_t) ((original_message_size_bits >> 32) & 0xff);
    padded_message[(size_t) (new_message_size_bits / 8) - 6] = (uint8_t) ((original_message_size_bits >> 40) & 0xff);
    padded_message[(size_t) (new_message_size_bits / 8) - 7] = (uint8_t) ((original_message_size_bits >> 48) & 0xff);
    padded_message[(size_t) (new_message_size_bits / 8) - 8] = (uint8_t) ((original_message_size_bits >> 56) & 0xff);

    // Process message
    uint32_t *message_blocks = (uint32_t *) padded_message;
    int number_of_blocks = (int) (new_message_size_bits / 512);
    for (int i = 0; i < number_of_blocks; i++) {
        uint32_t w[80];
        for (int j = 0; j < 16; j++) {
            w[j] = message_blocks[i * 16 + j];
        }
        for (int j = 16; j < 80; j++) {
            w[j] = LEFT_ROTATE(w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16], 1);
        }

        uint32_t a = h0, b = h1, c = h2, d = h3, e = h4, f = h5, g = h6, h = h7;
        for (int j = 0; j < 80; j++) {
            uint32_t temp1 = h + LEFT_ROTATE(e, 5) + ((f & g) | ((~f) & h)) + w[j] + 0x5a827999;
            uint32_t temp2 = LEFT_ROTATE(a, 30) + ((a & b) | (a & c) | (b & c));
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    // Generate final hash
    memcpy(hash, &h0, 4);
    memcpy(hash + 4, &h1, 4);
    memcpy(hash + 8, &h2, 4);
    memcpy(hash + 12, &h3, 4);
    memcpy(hash + 16, &h4, 4);
    memcpy(hash + 20, &h5, 4);
    memcpy(hash + 24, &h6, 4);
    memcpy(hash + 28, &h7, 4);

    // Free resources
    free(padded_message);
}