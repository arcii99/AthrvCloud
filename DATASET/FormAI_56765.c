//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Rotate left macro
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Custom hash function
uint32_t custom_hash(const void *input, size_t len) {

    // Initialize variables
    uint32_t hash = 0xFFFFFFFF;
    uint32_t prime = 0x01000193;
    const uint8_t *data = (const uint8_t *)input;

    // Loop through input bytes
    for (size_t i = 0; i < len; i++) {

        // XOR with input byte
        hash ^= data[i];

        // Multiply by prime number
        hash *= prime;

        // Rotate hash 2 bits to the left
        hash = ROTL(hash, 2);
    }

    // Return resulting hash
    return hash;
}

int main() {

    // Test input string
    const char *input_str = "Hello, world!";

    // Calculate hash
    uint32_t hash = custom_hash(input_str, strlen(input_str));

    // Print result
    printf("Input String: \"%s\"\n", input_str);
    printf("Hash Value: %08x\n", hash);

    return 0;
}