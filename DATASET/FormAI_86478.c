//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* SHA256 specific defines */
#define SHA256_BLOCK_SIZE 32
#define SHA256_DIGEST_SIZE 32

/* SHA256 context structure */
typedef struct {
    uint32_t state[8];
    uint64_t count;
    uint8_t buffer[64];
} sha256_ctx;

/* SHA256 constants */
static const uint32_t K[64] = {
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

/* SHA256 functions */
static uint32_t rotr(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}

static uint32_t ch(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (~x & z);
}

static uint32_t maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

static uint32_t sig0(uint32_t x)
{
    return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
}

static uint32_t sig1(uint32_t x)
{
    return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
}

static uint32_t eps0(uint32_t x)
{
    return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}

static uint32_t eps1(uint32_t x)
{
    return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

static void sha256_transform(sha256_ctx *ctx, const uint8_t *data)
{
    uint32_t i, j, t1, t2, m[64];

    /* Copy data to message blocks */
    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        m[i] = (((uint32_t)data[j]) << 24) |
               (((uint32_t)data[j + 1]) << 16) |
               (((uint32_t)data[j + 2]) << 8) |
               (((uint32_t)data[j + 3]));
    }

    /* Compute remaining message blocks */
    for (; i < 64; ++i) {
        m[i] = eps1(m[i - 2]) + m[i - 7] + eps0(m[i - 15]) + m[i - 16];
    }

    /* Initialize working variables */
    uint32_t a, b, c, d, e, f, g, h;

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    /* Computation */
    for (i = 0; i < 64; ++i) {
        t1 = h + sig1(e) + ch(e, f, g) + K[i] + m[i];
        t2 = sig0(a) + maj(a, b, c);

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    /* Update state */
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

/* SHA256 init function */
void sha256_init(sha256_ctx *ctx)
{
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;

    ctx->count = 0;
}

/* SHA256 update function */
void sha256_update(sha256_ctx *ctx, const uint8_t *data, size_t len)
{
    uint32_t i;

    for (i = 0; i < len; ++i) {
        ctx->buffer[ctx->count % 64] = data[i];
        ++ctx->count;

        if ((ctx->count % 64) == 0) {
            sha256_transform(ctx, ctx->buffer);
        }
    }
}

/* SHA256 final function */
void sha256_final(sha256_ctx *ctx, uint8_t *hash)
{
    uint32_t i;
    uint8_t *p;

    /* Pad message */
    ctx->buffer[ctx->count % 64] = 0x80;
    ++ctx->count;

    if ((ctx->count % 64) > 56) {
        while ((ctx->count % 64) != 0) {
            ctx->buffer[ctx->count % 64] = 0x00;
            ++ctx->count;
        }
    }

    while ((ctx->count % 64) < 56) {
        ctx->buffer[ctx->count % 64] = 0x00;
        ++ctx->count;
    }

    /* Append length */
    for (i = 56, p = (uint8_t *)&ctx->count; i < 64; ++i) {
        ctx->buffer[i] = p[7 - (i - 56)];
    }

    /* Final transformation */
    sha256_transform(ctx, ctx->buffer);

    /* Output hash */
    for (i = 0; i < SHA256_DIGEST_SIZE; ++i) {
        hash[i] = ctx->state[i / 4] >> (24 - 8 * (i % 4));
    }
}

/* Main function */
int main()
{
    sha256_ctx ctx;
    uint8_t hash[SHA256_DIGEST_SIZE];
    char input[256];
    int i;

    printf("Enter a string to hash: ");
    fgets(input, 256, stdin);

    /* Calculate hash */
    sha256_init(&ctx);
    sha256_update(&ctx, (uint8_t *)input, strlen(input));
    sha256_final(&ctx, hash);

    /* Print hash */
    printf("\nHash:\n");

    for (i = 0; i < SHA256_DIGEST_SIZE; ++i) {
        printf("%02x", hash[i]);
    }

    printf("\n");

    return 0;
}