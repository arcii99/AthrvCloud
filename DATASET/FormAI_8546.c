//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) ((x << n) | (x >> (32 - n))) // Define rotation left macro

// Define SHA-256 constants
const uint32_t K[] = {
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
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

typedef struct {
    uint8_t data[64];
    uint32_t datalen;
    uint32_t bitlen[2];
    uint32_t state[8];
} SHA256_CTX;

// Function prototypes
void sha256_transform(SHA256_CTX *ctx, const uint8_t *data);
void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const uint8_t *data, size_t len);
void sha256_final(SHA256_CTX *ctx, uint8_t *hash);

void sha256_transform(SHA256_CTX *ctx, const uint8_t *data) {
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

    // Prepare message schedule
    for (i = 0, j = 0; i < 16; ++i, j += 4)
        m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
    for (; i < 64; ++i)
        m[i] = m[i - 16] + m[i - 7] + ROTL(m[i - 15], 7) + ROTL(m[i - 15], 18);

    // Initialize working variables
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    // Compression loop
    for (i = 0; i < 64; ++i) {
        t1 = h + K[i] + m[i];
        if (i >= 48) {
            t1 += ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25);
            t2 = (e & f) ^ (~e & g);
        } else if (i >= 16) {
            t1 += ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25);
            t2 = (e & f) ^ (e & g) ^ (f & g);
        } else {
            t1 += ROTL(e, 2) ^ ROTL(e, 13) ^ ROTL(e, 22);
            t2 = (e & f) ^ (e & g) ^ (f & g);
        }
        t1 += t2;
        d += t1;
        h = g;
        g = f;
        f = e;
        e = d;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Update state
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

void sha256_init(SHA256_CTX *ctx) {
    ctx->datalen = 0;
    ctx->bitlen[0] = 0;
    ctx->bitlen[1] = 0;
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}

void sha256_update(SHA256_CTX *ctx, const uint8_t *data, size_t len) {
    uint32_t i;

    for (i = 0; i < len; ++i) {
        ctx->data[ctx->datalen] = data[i];
        ++ctx->datalen;
        if (ctx->datalen == 64) {
            sha256_transform(ctx, ctx->data);
            ctx->bitlen[0] += 512;
            ctx->datalen = 0;
        }
    }
}

void sha256_final(SHA256_CTX *ctx, uint8_t *hash) {
    uint32_t i;

    i = ctx->datalen;

    // Pad the input data so that its length is congruent to 448 modulo 512
    if (ctx->datalen < 56) {
        ctx->data[i++] = 0x80;
        while (i < 56)
            ctx->data[i++] = 0x00;
    } else {
        ctx->data[i++] = 0x80;
        while (i < 64)
            ctx->data[i++] = 0x00;
        sha256_transform(ctx, ctx->data);
        memset(ctx->data, 0, 56);
    }

    // Append the length of the input data (in bits) as a 64-bit big-endian integer
    ctx->bitlen[1] = ctx->datalen << 3;
    ctx->data[63] = (ctx->bitlen[1] >> 0) & 0xff;
    ctx->data[62] = (ctx->bitlen[1] >> 8) & 0xff;
    ctx->data[61] = (ctx->bitlen[1] >> 16) & 0xff;
    ctx->data[60] = (ctx->bitlen[1] >> 24) & 0xff;
    ctx->data[59] = (ctx->bitlen[0] >> 0) & 0xff;
    ctx->data[58] = (ctx->bitlen[0] >> 8) & 0xff;
    ctx->data[57] = (ctx->bitlen[0] >> 16) & 0xff;
    ctx->data[56] = (ctx->bitlen[0] >> 24) & 0xff;
    sha256_transform(ctx, ctx->data);

    // Output the 256-bit hash (in big-endian order)
    for (i = 0; i < 8; ++i) {
        hash[i * 4 + 0] = (ctx->state[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (ctx->state[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (ctx->state[i] >> 8) & 0xff;
        hash[i * 4 + 3] = (ctx->state[i] >> 0) & 0xff;
    }
}

int main(void) {
    uint8_t message[] = "Hello, world!";
    uint8_t hash[32];
    SHA256_CTX ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, message, strlen(message));
    sha256_final(&ctx, hash);

    for (int i = 0; i < sizeof(hash); ++i) {
        printf("%02x", hash[i]);
    }

    return 0;
}