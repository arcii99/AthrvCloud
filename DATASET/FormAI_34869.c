//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: minimalist
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))

uint32_t fmix32(uint32_t h){
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;

    return h;
}

uint32_t murmur3_32(const char* key, uint32_t len, uint32_t seed){
    const uint8_t* data = (const uint8_t*)key;
    const int nblocks = len / 4;

    uint32_t h1 = seed;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    uint32_t* blocks = (uint32_t*)(data + nblocks*4);

    for (int i = -nblocks; i; i++){
        uint32_t k1 = blocks[i];

        k1 *= c1;
        k1 = ROTL32(k1, 15);
        k1 *= c2;

        h1 ^= k1;
        h1 = ROTL32(h1, 13);
        h1 = h1*5+0xe6546b64;
    }

    const uint8_t* tail = (const uint8_t*)(data + nblocks*4);
    uint32_t k1 = 0;

    switch (len & 3)
    {
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
                k1 *= c1;
                k1 = ROTL32(k1,15);
                k1 *= c2;
                h1 ^= k1;
    };

    h1 ^= len;
    h1 = fmix32(h1);
    return h1;
}

int main(){
    char message[] = "hello world";
    uint32_t hash = murmur3_32(message, strlen(message), 0);

    printf("Hash: %u\n", hash);

    return 0;
}