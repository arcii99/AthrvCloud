//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) ((x << n) | (x >> (32 - n)))

uint32_t hash(const void *data, size_t size, uint32_t seed) {
    const char *input = (const char *) data;
    uint32_t h1 = seed;
    uint32_t c1 = 0xcc9e2d51;
    uint32_t c2 = 0x1b873593;
    uint32_t k1 = 0;
    uint32_t i = 0;
    uint32_t len = size / sizeof(uint32_t);

    while (len--) {
        k1 = ((const uint32_t*) input)[i++];
        k1 *= c1;
        k1 = ROTL(k1, 15);
        k1 *= c2;

        h1 ^= k1;
        h1 = ROTL(h1, 13);
        h1 = h1 * 5 + 0xe6546b64;
    }

    k1 = 0;
    len = size & 3;

    while (len--) {
        k1 <<= 8;
        k1 += input[i++];

        if (len == 0) {
            k1 *= c1;
            k1 = ROTL(k1, 15);
            k1 *= c2;
            h1 ^= k1;
        }
    }

    h1 ^= size;
    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    return h1;
}

int main() {
    const char *message = "This is a message";
    uint32_t hash_seed = 0x12345678;
    uint32_t hash_value = hash(message, strlen(message), hash_seed);

    printf("Hash of \"%s\": %08x\n", message, hash_value);

    return 0;
}