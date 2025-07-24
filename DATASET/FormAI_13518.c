//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))

uint32_t hash(const char* message, size_t message_len, uint32_t seed) {
    uint32_t h1 = seed;
    uint32_t c1 = 0x997ee900;
    uint32_t c2 = 0x98a7b300;
    const uint32_t* message32 = (const uint32_t*) message;
    size_t i;

    for (i = 0; i + 1 < message_len / 4; i += 2) {
        uint32_t k1 = message32[i];
        uint32_t k2 = message32[i+1];

        k1 *= c1; k1 = ROTL(k1, 13); k1 *= c2; h1 ^= k1;
        k2 *= c1; k2 = ROTL(k2, 13); k2 *= c2; h1 ^= k2;
        h1 = ROTL(h1, 15); h1 *= 5; h1 += 0x52dce729;
    }

    if (message_len % 4 != 0) {
        uint32_t k1 = 0;
        uint32_t k2 = 0;
        const uint8_t* tail = (const uint8_t*) (message + i*4);
        switch (message_len % 4) {
            case 3: k2 ^= tail[2] << 16;
            case 2: k2 ^= tail[1] << 8;
            case 1: k2 ^= tail[0];
                k2 *= c1; k2 = ROTL(k2, 13); k2 *= c2; h1 ^= k2;
        }
        h1 ^= message_len;
        h1 = ROTL(h1, 15);
        h1 *= 5;
        h1 += 0x52dce729;
    }
    return h1;
}

int main() {
    const char* message = "Hello, world!";
    uint32_t seed = 42;
    uint32_t hash_output = hash(message, strlen(message), seed);
    printf("The hash of \"%s\" with seed %u is: %u", message, seed, hash_output);
    return 0;
}