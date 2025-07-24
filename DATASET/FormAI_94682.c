//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define ROTATE_LEFT(value, shift) ((value << shift) | (value >> (32 - shift)))

uint32_t retro_hash(const void *data, size_t size)
{
    const uint8_t *bytes = (const uint8_t *)data;
    uint32_t hash = 0xc0ffee;
    for (size_t i = 0; i < size; i++) {
        hash = ROTATE_LEFT(hash, 5) ^ bytes[i];
    }
    return hash;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s <data>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *data = argv[1];
    size_t size = strlen(data);
    uint32_t hash = retro_hash(data, size);
    printf("Hash of '%s': 0x%08x\n", data, hash);
    return EXIT_SUCCESS;
}