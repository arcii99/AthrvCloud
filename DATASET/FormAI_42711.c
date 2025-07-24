//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL64(x, y) (((x) << (y)) | ((x) >> (64 - (y))))

uint64_t murmur_hash(const void* key, const int len) {
    const uint64_t seed = 0x9747b28c6187d32d;
    const uint64_t m = 0xc6a4a7935bd1e995;
    const uint64_t r = 47;
    uint64_t h = seed ^ (len * m);

    const uint64_t* data = (const uint64_t*)key;
    const uint64_t* end = data + (len / sizeof(uint64_t));

    while (data != end) {
        uint64_t k = *data++;

        k *= m;
        k ^= k >> r;
        k *= m;

        h ^= k;
        h *= m;
    }

    const unsigned char* data2 = (const unsigned char*)data;

    switch (len & 7) {
    case 7: h ^= (uint64_t)(data2[6]) << 48;
    case 6: h ^= (uint64_t)(data2[5]) << 40;
    case 5: h ^= (uint64_t)(data2[4]) << 32;
    case 4: h ^= (uint64_t)(data2[3]) << 24;
    case 3: h ^= (uint64_t)(data2[2]) << 16;
    case 2: h ^= (uint64_t)(data2[1]) << 8;
    case 1: h ^= (uint64_t)(data2[0]); h *= m;
    };

    h ^= h >> r;
    h *= m;
    h ^= h >> r;

    return h;
}

int main() {
    const char* message = "Hello, world!";
    uint64_t hash = murmur_hash(message, strlen(message));
    printf("'%s' hash: %llu\n", message, (unsigned long long)hash);

    return 0;
}