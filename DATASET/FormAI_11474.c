//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x,y) ((x << y) | (x >> (32 - y)))

uint32_t fmix(uint32_t h)
{
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

void MurmurHash3_x86_32(const void * key, int len, uint32_t seed, void * out)
{
    const uint8_t * data = (const uint8_t*)key;
    const int nblocks = len / 4;

    uint32_t h1 = seed;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    const uint32_t * blocks = (const uint32_t *)(data + nblocks*4);

    for(int i = -nblocks; i; i++)
    {
        uint32_t k1 = blocks[i];

        k1 *= c1;
        k1 = ROTL32(k1, 15);
        k1 *= c2;

        h1 ^= k1;
        h1 = ROTL32(h1, 13); 
        h1 = h1*5+0xe6546b64;
    }

    const uint8_t * tail = (const uint8_t*)(data + nblocks*4);

    uint32_t k1 = 0;

    switch(len & 3)
    {
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
        k1 *= c1; k1 = ROTL32(k1, 15); k1 *= c2; h1 ^= k1;
    };

    h1 ^= len;

    h1 = fmix(h1);

    *(uint32_t*)out = h1;
}

int main()
{
    char str[256] = "Hello, World!";
    uint32_t hash = 0;

    MurmurHash3_x86_32(str, strlen(str), 0, &hash);

    printf("Hash: %u\n", hash);

    return 0;
}