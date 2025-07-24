//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

#define FMIX(h)                                \
    do {                                       \
        (h) ^= (h) >> 16;                      \
        (h) *= 0x85ebca6b;                     \
        (h) ^= (h) >> 13;                      \
        (h) *= 0xc2b2ae35;                     \
        (h) ^= (h) >> 16;                      \
    } while (0)

uint32_t murmur3(const uint8_t *key, size_t len, uint32_t seed) {
    uint32_t h = seed;
    if (len > 3) {
        const uint32_t *key_x4 = (const uint32_t *) key;
        size_t i = len >> 2;
        do {
            uint32_t k = *key_x4++;
            k *= 0xcc9e2d51;
            k = ROTR(k, 15);
            k *= 0x1b873593;
            h ^= k;
            h = ROTR(h, 13);
            h = h * 5 + 0xe6546b64;
        } while (--i);
        key = (const uint8_t *) key_x4;
    }
    if (len & 3) {
        size_t i = len & 3;
        uint32_t k = 0;
        key = &key[i - 1];
        do {
            k <<= 8;
            k |= *key--;
        } while (--i);
        k *= 0xcc9e2d51;
        k = ROTR(k, 15);
        k *= 0x1b873593;
        h ^= k;
    }
    h ^= len;
    FMIX(h);
    return h;
}

int main() {
    char str[] = "cyberpunk";
    uint32_t hash = murmur3((const uint8_t *) str, strlen(str), 0);
    printf("The hash of \"%s\" is: %lu\n", str, hash);
    return 0;
}