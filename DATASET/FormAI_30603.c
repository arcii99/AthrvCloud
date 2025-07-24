//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t rotate_left(uint32_t x, uint32_t n) {
    return (x << n) | (x >> (32 - n));
}

uint32_t hash_block(uint8_t *block, uint32_t hash) {
    #define GET_UINT32(n) \
        (((uint32_t)block[(n) + 0] << 24) | \
         ((uint32_t)block[(n) + 1] << 16) | \
         ((uint32_t)block[(n) + 2] << 8)  | \
         ((uint32_t)block[(n) + 3] << 0))

    #define PUT_UINT32(n, v) \
        do { \
            block[(n) + 0] = (uint8_t)((v) >> 24); \
            block[(n) + 1] = (uint8_t)((v) >> 16); \
            block[(n) + 2] = (uint8_t)((v) >> 8); \
            block[(n) + 3] = (uint8_t)((v) >> 0); \
        } while (0)

    static const uint32_t k[64] = {
        // First 16 constants
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        // Second 16 constants
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        // Third 16 constants
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x811c9dc5, 0x8f1bbcdc,
        0x9c100d4c, 0xa0e6733f, 0xa76f9882, 0xb7be5bdc,
        0xcbb41ef9, 0xd4c19c6f, 0xe1cafe29, 0xe5c7e361,
        // Fourth 16 constants
        0x0d76f988, 0x103e7e6f, 0x19dc84c7, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        // Fifth 16 constants
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        // Sixth 16 constants
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t i;

    for (i = 0; i < 16; i++) {
        w[i] = GET_UINT32(i * 4);
    }
    for (i = 16; i < 64; i++) {
        uint32_t s0 = rotate_left(w[i-15], 7) ^ rotate_left(w[i-15], 18) ^ (w[i-15] >> 3);
        uint32_t s1 = rotate_left(w[i-2], 17) ^ rotate_left(w[i-2], 19) ^ (w[i-2] >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }

    a = hash;
    b = 0x6a09e667;
    c = 0xbb67ae85;
    d = 0x3c6ef372;
    e = 0xa54ff53a;
    f = 0x510e527f;
    g = 0x9b05688c;
    h = 0x1f83d9ab;

    for (i = 0; i < 64; i++) {
        uint32_t s1 = rotate_left(e, 6) ^ rotate_left(e, 11) ^ rotate_left(e, 25);
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t temp1 = h + s1 + ch + k[i] + w[i];
        uint32_t s0 = rotate_left(a, 2) ^ rotate_left(a, 13) ^ rotate_left(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = s0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    return hash + a;
}

void hash_message(const uint8_t *message, size_t length, uint8_t *hash) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    size_t i;
    uint8_t block[64];
    uint32_t hash_val;

    for (i = 0; i < length / 64; i++) {
        memcpy(block, message + i * 64, 64);
        hash_val = hash_block(block, h[0]);
        h[0] = hash_val;
    }

    memset(block, 0, 64);
    memcpy(block, message + i * 64, length % 64);
    block[length % 64] = 0x80;
    if (length % 64 >= 56) {
        hash_val = hash_block(block, h[0]);
        h[0] = hash_val;
        memset(block, 0, 64);
    }

    uint64_t bits = length * 8;
    PUT_UINT32(56, (uint32_t)(bits >> 32));
    PUT_UINT32(60, (uint32_t)(bits & 0xffffffff));
    hash_val = hash_block(block, h[0]);
    h[0] = hash_val;

    for (i = 0; i < 8; i++) {
        PUT_UINT32(i * 4, h[i]);
    }

    memcpy(hash, block, 32);
}

int main() {
    const char *message = "Hello, world!";
    uint8_t hash[32];

    hash_message((const uint8_t *)message, strlen(message), hash);

    printf("Message: %s\nHash: ", message);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}