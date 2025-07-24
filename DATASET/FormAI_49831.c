//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Returns a 64-bit hash value using the CityHash algorithm
uint64_t hash(const char *str, size_t len) {
    const uint64_t kMul = 0x9ddfea08eb382d69ULL;
    const uint64_t kSeed = 0xdeadbeef12345678ULL;
    const uint64_t *data = (const uint64_t*) str;
    const uint8_t *tail = (const uint8_t*) (str + (len & ~7));
    const int kLen = len / 8;
    uint64_t h = kSeed ^ (kMul * len);
    uint64_t v;

    for (int i = 0; i < kLen; i++) {
        v = data[i];
        v *= kMul;
        v ^= v >> 47;
        v *= kMul;
        h ^= v;
        h *= kMul;
    }

    switch (len & 7) {
        case 7: h ^= (uint64_t) tail[6] << 48;
        case 6: h ^= (uint64_t) tail[5] << 40;
        case 5: h ^= (uint64_t) tail[4] << 32;
        case 4: h ^= (uint64_t) tail[3] << 24;
        case 3: h ^= (uint64_t) tail[2] << 16;
        case 2: h ^= (uint64_t) tail[1] << 8;
        case 1: h ^= (uint64_t) tail[0];
                h *= kMul;
    }

    h ^= h >> 47;
    h *= kMul;
    h ^= h >> 47;
    return h;
}

int main() {
    char *input = "This is a test string";
    uint64_t result = hash(input, strlen(input));
    printf("Hash of '%s': %llu", input, (unsigned long long) result);
    return 0;
}