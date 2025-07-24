//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))

uint32_t hash(char *key, uint32_t len, uint32_t seed)
{
    uint32_t h1 = seed;
    uint32_t c1 = 0xcc9e2d51;
    uint32_t c2 = 0x1b873593;
    uint32_t *blocks;
    uint32_t block_size = 4;
    uint32_t i, k;

    if (key == NULL || len == 0) {
        return 0;
    }

    h1 ^= len;
    blocks = (uint32_t*) key;

    for (i = 0; i < len / block_size; i++) {
        k = blocks[i];
        k *= c1;
        k = ROTL(k, 15);
        k *= c2;
    
        h1 ^= k;
        h1 = ROTL(h1, 13); 
        h1 = h1*5+0xe6546b64;
    }

    k = 0;
    for (i = (len & ~3); i < len; i++) {
        k |= ((uint32_t) key[i]) << ((i%4) * 8);
    }

    k *= c1;
    k = ROTL(k, 15);
    k *= c2;
    h1 ^= k;

    h1 ^= len;

    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    return h1;
}
int main()
{
    char *str = "Hello, World!";
    uint32_t len = strlen(str);
    uint32_t seed = 0; // set seed
    uint32_t hashval = hash(str, len, seed);

    printf("Input string: %s\n", str);
    printf("Hash value: %u\n", hashval);

    return 0;
}