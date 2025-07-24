//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: mathematical
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void hash_function(const char *in, size_t in_len, uint32_t seed, uint32_t *out) {
    uint32_t hash = seed;

    for (size_t i = 0; i < in_len; i++) {
        hash = hash ^ in[i];
        hash = hash * 0xD1111111;
    }

    *out = hash;
}

int main(void) {
    const char *in = "Hello, World!";
    size_t in_len = 13;
    uint32_t seed = 0;
    uint32_t out;

    hash_function(in, in_len, seed, &out);

    printf("Output hash: %u\n", out);

    return EXIT_SUCCESS;
}