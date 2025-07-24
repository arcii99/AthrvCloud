//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROTL(x, b) (((x) << (b)) | ((x) >> (32 - (b))))

uint32_t fmix32(uint32_t h)
{
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

uint32_t MurmurHash3_x86_32(const void *key, size_t len, uint32_t seed)
{
    const uint8_t *data = (const uint8_t *)key;
    const int nblocks = len / 4;
    uint32_t h1 = seed;
    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;
    const uint32_t *blocks = (const uint32_t *)(data + nblocks * 4);
    for (int i = -nblocks; i; i++)
    {
        uint32_t k1 = 0;
        if (i != 0)
        {
            k1 = blocks[i];
        }
        else
        {
            memcpy(&k1, data + nblocks * 4, len & 3);
        }
        k1 *= c1;
        k1 = ROTL(k1, 15);
        k1 *= c2;
        h1 ^= k1;
        h1 = ROTL(h1, 13);
        h1 = h1 * 5 + 0xe6546b64;
    }
    h1 ^= len;
    h1 = fmix32(h1);
    return h1;
}

int main()
{
    char input[] = "Hello, world!";
    uint32_t hash = MurmurHash3_x86_32(input, strlen(input), 0);
    printf("%d\n", hash);
    return 0;
}