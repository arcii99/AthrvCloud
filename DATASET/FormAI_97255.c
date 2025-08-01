//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define BIG_CONSTANT(x) (x##LLU)

static const uint32_t c1 = 0x239b961b;
static const uint32_t c2 = 0xab0e9789;
static const uint32_t c3 = 0x38b34ae5;
static const uint32_t c4 = 0xa1e38b93;

void murmurhash3_128(const void* key, const int len, const uint32_t seed, void* out) {
    const uint8_t* data = (const uint8_t*)key;
    const int nblocks = len / 16;
    uint64_t h1 = seed;
    uint64_t h2 = seed;
    uint64_t k1 = 0;
    uint64_t k2 = 0;
    const uint64_t* blocks = (const uint64_t*)(data);

    for(int i = 0; i < nblocks; i++) {
        k1 = blocks[i*2];
        k2 = blocks[i*2+1];

        k1 *= c1; k1  = ROTL(k1,31); k1 *= c2; h1 ^= k1;

        h1 = ROTL(h1,27); h1 += h2; h1 = h1*5+0x52dce729;

        k2 *= c2; k2  = ROTL(k2,33); k2 *= c3; h2 ^= k2;

        h2 = ROTL(h2,31); h2 += h1; h2 = h2*5+0x38495ab5;
    }

    const uint8_t* tail = (const uint8_t*)(data + nblocks*16);
    uint64_t k1Tail = 0;
    uint64_t k2Tail = 0;

    switch(len & 15) {
        case 15: k2Tail ^= (uint64_t)(tail[14]) << 48;
        case 14: k2Tail ^= (uint64_t)(tail[13]) << 40;
        case 13: k2Tail ^= (uint64_t)(tail[12]) << 32;
        case 12: k2Tail ^= (uint64_t)(tail[11]) << 24;
        case 11: k2Tail ^= (uint64_t)(tail[10]) << 16;
        case 10: k2Tail ^= (uint64_t)(tail[ 9]) << 8;
        case  9: k2Tail ^= (uint64_t)(tail[ 8]) << 0;
                 k2Tail *= c3; k2Tail  = ROTL(k2Tail,33); k2Tail *= c4; h2 ^= k2Tail;

        case  8: k1Tail ^= (uint64_t)(tail[ 7]) << 56;
        case  7: k1Tail ^= (uint64_t)(tail[ 6]) << 48;
        case  6: k1Tail ^= (uint64_t)(tail[ 5]) << 40;
        case  5: k1Tail ^= (uint64_t)(tail[ 4]) << 32;
        case  4: k1Tail ^= (uint64_t)(tail[ 3]) << 24;
        case  3: k1Tail ^= (uint64_t)(tail[ 2]) << 16;
        case  2: k1Tail ^= (uint64_t)(tail[ 1]) << 8;
        case  1: k1Tail ^= (uint64_t)(tail[ 0]) << 0;
                 k1Tail *= c1; k1Tail  = ROTL(k1Tail,31); k1Tail *= c2; h1 ^= k1Tail;
    }

    h1 ^= len; h2 ^= len;

    h1 += h2;
    h2 += h1;

    h1 = h1 ^ (h1 >> 33); h1 *= BIG_CONSTANT(0xff51afd7ed558ccd);
    h1 = h1 ^ (h1 >> 33); h1 *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
    h1 = h1 ^ (h1 >> 33);

    h2 = h2 ^ (h2 >> 33); h2 *= BIG_CONSTANT(0xff51afd7ed558ccd);
    h2 = h2 ^ (h2 >> 33); h2 *= BIG_CONSTANT(0xc4ceb9fe1a85ec53);
    h2 = h2 ^ (h2 >> 33);

    uint64_t* o = (uint64_t*)out;
    o[0] = h1;
    o[1] = h2;
}

int main() {
    char str[] = "Hello, world!";
    uint64_t hash[2];

    memset(hash, 0, sizeof(hash));

    murmurhash3_128(str, strlen(str), 12345, hash);

    printf("Hash: %016llx%016llx\n", hash[0], hash[1]);
    return 0;
}