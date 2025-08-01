//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x, y) ((x >> y) | (x << (32 - y)))

#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

#define SIGMA0(x) (ROTR32(x, 2) ^ ROTR32(x, 13) ^ ROTR32(x, 22))
#define SIGMA1(x) (ROTR32(x, 6) ^ ROTR32(x, 11) ^ ROTR32(x, 25))
#define sigma0(x) (ROTR32(x, 7) ^ ROTR32(x, 18) ^ (x >> 3))
#define sigma1(x) (ROTR32(x, 17) ^ ROTR32(x, 19) ^ (x >> 10))

uint32_t H[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19};

const uint32_t K[64] = {
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
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

void sha256_transform(uint32_t *state, const uint8_t *data)
{
    uint32_t a, b, c, d, e, f, g, h, t1, t2, m[64];
    int i, j;

    for (i = 0, j = 0; i < 16; ++i, j += 4)
        m[i] = (data[j] << 24) | (data[j + 1] << 16) |
               (data[j + 2] << 8) | (data[j + 3]);
    for (; i < 64; ++i)
        m[i] = sigma1(m[i - 2]) + m[i - 7] + sigma0(m[i - 15]) + m[i - 16];

    a = state[0], b = state[1], c = state[2], d = state[3],
    e = state[4], f = state[5], g = state[6], h = state[7];

    for (i = 0; i < 64; ++i)
    {
        t1 = h + SIGMA1(e) + CH(e, f, g) + K[i] + m[i];
        t2 = SIGMA0(a) + MAJ(a, b, c);
        h = g, g = f, f = e, e = d + t1, d = c, c = b, b = a, a = t1 + t2;
    }

    state[0] += a, state[1] += b, state[2] += c, state[3] += d,
        state[4] += e, state[5] += f, state[6] += g, state[7] += h;
}

void sha256_hash(const uint8_t *data, size_t len, uint8_t *hash)
{
    uint32_t state[8], i;
    size_t n;

    state[0] = 0x6a09e667, state[1] = 0xbb67ae85, state[2] = 0x3c6ef372,
    state[3] = 0xa54ff53a, state[4] = 0x510e527f, state[5] = 0x9b05688c,
    state[6] = 0x1f83d9ab, state[7] = 0x5be0cd19;

    for (n = len; n >= 64; n -= 64, data += 64)
        sha256_transform(state, data);

    uint8_t block[64];
    memcpy(block, data, n);
    block[n] = 0x80;
    if (n > 55)
    {
        sha256_transform(state, block);
        memset(block, 0, 64);
    }
    *((uint64_t *)(block + 56)) = len * 8;
    sha256_transform(state, block);

    for (i = 0; i < 8; ++i)
        *((uint32_t *)(hash + i * 4)) = state[i];
}

int main()
{
    const char *msg = "Hello World!";
    uint8_t hash[32];
    sha256_hash((uint8_t *)msg, strlen(msg), hash);
    for (int i = 0; i < 32; ++i)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}