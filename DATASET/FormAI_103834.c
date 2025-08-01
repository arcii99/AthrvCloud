//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, b) (uint32_t)(((x) << (b)) | ((x) >> (32 - (b))))

#define BIG_CONSTANT(x) (x##LLU)

static inline uint32_t getblock(const uint32_t * p, int i)
{
    return p[i];
}

static inline uint32_t fmix(uint32_t h)
{
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;

    return h;
}

uint32_t MurmurHash3_x86_32(const void * key, int len, uint32_t seed)
{
    const uint8_t * data = (const uint8_t*)key;
    const int nblocks = len / 4;

    uint32_t h1 = seed;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    const uint32_t * blocks = (const uint32_t *)(data + nblocks*4);

    for (int i = -nblocks; i; i++)
    {
        uint32_t k1 = getblock(blocks,i);

        k1 *= c1;
        k1 = ROTL(k1, 15);
        k1 *= c2;

        h1 ^= k1;
        h1 = ROTL(h1, 13);
        h1 = h1*5+0xe6546b64;
    }

    const uint8_t * tail = (const uint8_t*)(data + nblocks*4);

    uint32_t k1 = 0;

    switch (len & 3)
    {
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
                k1 *= c1;
                k1 = ROTL(k1, 15);
                k1 *= c2;
                h1 ^= k1;
    }

    h1 ^= len;

    h1 = fmix(h1);

    return h1;
}

int main()
{
    char string[] = "This is a sample string for hashing.";
    uint32_t seed = 123456;
    uint32_t result = MurmurHash3_x86_32(string, strlen(string), seed);

    printf("The hash of the string \"%s\" with seed %u is: %u\n", string, seed, result);

    return 0;
}