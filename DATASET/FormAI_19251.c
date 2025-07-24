//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: high level of detail
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define ROTATE_RIGHT(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

/* Initial hash values */
static const uint32_t initial_hash_values[] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

/* Round constants */
static const uint32_t k[] = {
    0x428a2f98,
    0x71374491,
    0xb5c0fbcf,
    0xe9b5dba5,
    0x3956c25b,
    0x59f111f1,
    0x923f82a4,
    0xab1c5ed5,
    0xd807aa98,
    0x12835b01,
    0x243185be,
    0x550c7dc3,
    0x72be5d74,
    0x80deb1fe,
    0x9bdc06a7,
    0xc19bf174,
    0xe49b69c1,
    0xefbe4786,
    0x0fc19dc6,
    0x240ca1cc,
    0x2de92c6f,
    0x4a7484aa,
    0x5cb0a9dc,
    0x76f988da,
    0x983e5152,
    0xa831c66d,
    0xb00327c8,
    0xbf597fc7,
    0xc6e00bf3,
    0xd5a79147,
    0x06ca6351,
    0x14292967,
    0x27b70a85,
    0x2e1b2138,
    0x4d2c6dfc,
    0x53380d13,
    0x650a7354,
    0x766a0abb,
    0x81c2c92e,
    0x92722c85,
    0xa2bfe8a1,
    0xa81a664b,
    0xc24b8b70,
    0xc76c51a3,
    0xd192e819,
    0xd6990624,
    0xf40e3585,
    0x106aa070,
    0x19a4c116,
    0x1e376c08,
    0x2748774c,
    0x34b0bcb5,
    0x391c0cb3,
    0x4ed8aa4a,
    0x5b9cca4f,
    0x682e6ff3,
    0x748f82ee,
    0x78a5636f,
    0x84c87814,
    0x8cc70208,
    0x90befffa,
    0xa4506ceb,
    0xbef9a3f7,
    0xc67178f2
};

/* SHA-256 works on blocks of 512 bits (64 bytes) */
typedef struct {
    uint8_t data[64];
    uint32_t datalen;
    uint32_t bitlen[2];
    uint32_t state[8];
} sha256_ctx;

/* SHA-256 initialization function */
void sha256_init(sha256_ctx *ctx)
{
    ctx->datalen = 0;
    ctx->bitlen[0] = 0;
    ctx->bitlen[1] = 0;
    memcpy(ctx->state, initial_hash_values, sizeof(initial_hash_values));
}

/* SHA-256 transform function */
void sha256_transform(sha256_ctx *ctx, const uint8_t *data)
{
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

    /* Convert the data to a big-endian 32-bit word array */
    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        m[i] = ((uint32_t)data[j] << 24) | ((uint32_t)data[j + 1] << 16) |
            ((uint32_t)data[j + 2] << 8) | ((uint32_t)data[j + 3]);
    }

    /* Extend the sixteen 32-bit words into sixty-four 32-bit words */
    for (; i < 64; ++i) {
        m[i] = m[i - 16] + ROTATE_RIGHT(m[i - 15], 7) + m[i - 7] +
            ROTATE_RIGHT(m[i - 2], 17);
    }

    /* Initialize working variables to the current hash value */
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    /* Compression function main loop */
    for (i = 0; i < 64; ++i) {
        t1 = h + ROTATE_RIGHT(e, 6) + CH(e, f, g) + k[i] + m[i];
        t2 = ROTATE_RIGHT(a, 2) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    /* Add the compressed chunk to the current hash value */
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

/* SHA-256 update function */
void sha256_update(sha256_ctx *ctx, const uint8_t *data, size_t len)
{
    size_t i;

    for (i = 0; i < len; ++i) {
        ctx->data[ctx->datalen++] = data[i];
        if (ctx->datalen == 64) {
            sha256_transform(ctx, ctx->data);
            ctx->bitlen[0] += 512;
            ctx->bitlen[1] += (ctx->bitlen[0] < 512 ? 1 : 0);
            ctx->datalen = 0;
        }
    }
}

/* SHA-256 finalization function */
void sha256_final(sha256_ctx *ctx, uint8_t *hash)
{
    uint32_t i;

    /*
     * Pad the message so that its length is congruent to 448 modulo 512,
     * then append the 64-bit message length in big-endian order
     */
    ctx->bitlen[0] += ctx->datalen * 8;
    ctx->bitlen[1] += (ctx->bitlen[0] < ctx->datalen * 8 ? 1 : 0);
    ctx->data[ctx->datalen++] = 0x80;
    while (ctx->datalen % 64 != 56) {
        ctx->data[ctx->datalen++] = 0x00;
    }
    for (i = 0; i < 8; ++i) {
        ctx->data[ctx->datalen++] = (uint8_t)(ctx->bitlen[1] >> (24 - i * 8));
    }
    for (i = 0; i < 4; ++i) {
        ctx->data[ctx->datalen++] = (uint8_t)(ctx->bitlen[0] >> (24 - i * 8));
    }

    /* Perform the final transformation */
    sha256_transform(ctx, ctx->data);

    /* Output the hash */
    for (i = 0; i < 32; ++i) {
        hash[i] = (uint8_t)(ctx->state[i >> 2] >> ((3 - (i & 3)) << 3));
    }
}

/* Main function to compute SHA-256 hash */
void sha256(uint8_t *input, size_t len, uint8_t *hash)
{
    sha256_ctx ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, input, len);
    sha256_final(&ctx, hash);
}

/* Example usage */
int main(void)
{
    uint8_t input[] = "This is a message to be hashed using SHA-256";
    uint8_t hash[32];

    sha256(input, sizeof(input) - 1, hash);

    printf("Hash:");
    for (size_t i = 0; i < sizeof(hash); ++i) {
        printf(" %02x", hash[i]);
    }
    printf("\n");

    return 0;
}