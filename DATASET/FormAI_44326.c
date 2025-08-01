//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, b) (uint32_t)(((x) << (b)) | ((x) >> (32 - (b))))
#define ROTR(x, b) (uint32_t)(((x) >> (b)) | ((x) << (32 - (b))))
#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1

uint32_t readU32(const void *ptr, int order) {
    uint32_t val = *((const uint32_t *)ptr);
    return order == LITTLE_ENDIAN ? val : (ROTL(val, 24) & 0xFF000000)
        | (ROTL(val, 8) & 0x00FF0000)
        | (ROTR(val, 8) & 0x0000FF00)
        | (ROTR(val, 24) & 0x000000FF);
}

uint32_t f1(uint32_t x) {
    return ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25);
}

uint32_t f2(uint32_t x) {
    return ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22);
}

uint32_t f3(uint32_t x) {
    return ROTL(x, 7) ^ ROTL(x, 18) ^ ROTR(x, 3);
}

uint32_t f4(uint32_t x) {
    return ROTL(x, 17) ^ ROTL(x, 19) ^ ROTR(x, 10);
}

void sha256(const void *data, size_t len, uint8_t *hash) {
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    uint32_t k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
    };

    size_t remain = len, blockCount = 1;
    size_t rounds = (len + 4) / 64 + 1;
    while (remain > 64) { blockCount++; remain -= 64; }
    char *msg = malloc(blockCount * 64);
    memcpy(msg, data, len);

    uint64_t bitCount = (uint64_t)len << 3;
    memset(msg + len, 0, 56 - remain);
    msg[len] = 0x80;
    if (blockCount * 64 - len >= 8)
        remain = 0;
    *(uint64_t *)(msg + blockCount * 64 - 8) = remain + bitCount;

    uint32_t *w = (uint32_t *)msg;
    for (size_t round = 0; round < rounds; round++) {
        uint32_t a = state[0], b = state[1], c = state[2], d = state[3],
                 e = state[4], f = state[5], g = state[6], h = state[7];

        for (int i = 0; i < 64; ++i) {
            uint32_t temp1 = h + f1(e) + ((e & f) ^ ((~e) & g)) + k[i] + w[i];
            uint32_t temp2 = f2(a) + ((a & b) ^ (a & c) ^ (b & c));
            temp1 += temp2;
            h = g; g = f; f = e; e = d + temp1; d = c; c = b; b = a; a = temp1 + temp2;
        }

        state[0] += a; state[1] += b; state[2] += c; state[3] += d;
        state[4] += e; state[5] += f; state[6] += g; state[7] += h;

        w += 16;
    }
    free(msg);

    for (int i = 0; i < 8; ++i) {
        uint32_t v = state[i];
        hash[i * 4] = (v >> 24) & 0xFF;
        hash[i * 4 + 1] = (v >> 16) & 0xFF;
        hash[i * 4 + 2] = (v >> 8) & 0xFF;
        hash[i * 4 + 3] = v & 0xFF;
    }
}

int main() {
    char data[] = "Hello, World!";
    uint8_t hash[32];
    sha256(data, strlen(data), hash);
    printf("Hash: ");
    for (int i = 0; i < 32; ++i)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}