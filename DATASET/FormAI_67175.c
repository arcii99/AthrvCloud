//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SHA512_BLOCK_SIZE 128
#define ROTR(x, n) (((x) >> (n)) | ((x) << (64 - (n))))
#define SHR(x, n) ((x) >> (n))
#define CH(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define SIGMA_0(x) (ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39))
#define SIGMA_1(x) (ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41))
#define sigma_0(x) (ROTR(x, 1) ^ ROTR(x, 8) ^ SHR(x, 7))
#define sigma_1(x) (ROTR(x, 19) ^ ROTR(x, 61) ^ SHR(x, 6))

typedef struct {
    uint64_t h[8];
    uint64_t len;
    uint64_t total_len;
    uint8_t block[SHA512_BLOCK_SIZE];
} sha512_ctx;

const uint64_t K[] = {
    0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
    0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
    0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
    0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
    0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
    0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
    0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
    0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
    0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
    0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
    0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
    0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
    0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
    0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
    0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
    0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
    0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
    0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
    0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

static void sha512_transform(sha512_ctx *ctx, const uint8_t data[])
{
    uint64_t a, b, c, d, e, f, g, h, t1, t2, m[80];
    int i, j;

    for (i = 0, j = 0; i < 16; ++i, j += 8) {
        m[i] = ((uint64_t)data[j + 0] << 56) |
               ((uint64_t)data[j + 1] << 48) |
               ((uint64_t)data[j + 2] << 40) |
               ((uint64_t)data[j + 3] << 32) |
               ((uint64_t)data[j + 4] << 24) |
               ((uint64_t)data[j + 5] << 16) |
               ((uint64_t)data[j + 6] <<  8) |
               ((uint64_t)data[j + 7] <<  0);
    }

    for ( ; i < 80; ++i) {
        m[i] = sigma_1(m[i - 2]) + m[i - 7] + sigma_0(m[i - 15]) + m[i - 16];
    }

    a = ctx->h[0];
    b = ctx->h[1];
    c = ctx->h[2];
    d = ctx->h[3];
    e = ctx->h[4];
    f = ctx->h[5];
    g = ctx->h[6];
    h = ctx->h[7];

    for (i = 0; i < 80; ++i) {
        t1 = h + SIGMA_1(e) + CH(e, f, g) + K[i] + m[i];
        t2 = SIGMA_0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    ctx->h[0] += a;
    ctx->h[1] += b;
    ctx->h[2] += c;
    ctx->h[3] += d;
    ctx->h[4] += e;
    ctx->h[5] += f;
    ctx->h[6] += g;
    ctx->h[7] += h;
}

void sha512_init(sha512_ctx *ctx)
{
    ctx->h[0] = 0x6a09e667f3bcc908;
    ctx->h[1] = 0xbb67ae8584caa73b;
    ctx->h[2] = 0x3c6ef372fe94f82b;
    ctx->h[3] = 0xa54ff53a5f1d36f1;
    ctx->h[4] = 0x510e527fade682d1;
    ctx->h[5] = 0x9b05688c2b3e6c1f;
    ctx->h[6] = 0x1f83d9abfb41bd6b;
    ctx->h[7] = 0x5be0cd19137e2179;
    ctx->len = 0;
    ctx->total_len = 0;
}

void sha512_update(sha512_ctx *ctx, const uint8_t data[], uint64_t len)
{
    uint64_t i;

    for (i = 0; i < len; ++i) {
        ctx->block[ctx->len++] = data[i];
        if (ctx->len == SHA512_BLOCK_SIZE) {
            sha512_transform(ctx, ctx->block);
            ctx->total_len += SHA512_BLOCK_SIZE;
            ctx->len = 0;
        }
    }
}

void sha512_finalize(sha512_ctx *ctx, uint8_t hash[])
{
    uint64_t i;

    i = ctx->len;

    /* Pad whatever bytes are left in the buffer */
    if (ctx->len < SHA512_BLOCK_SIZE - 16) {
        ctx->block[i++] = 0x80;
        while (i < SHA512_BLOCK_SIZE - 8) {
            ctx->block[i++] = 0x00;
        }
    } else {
        ctx->block[i++] = 0x80;
        while (i < SHA512_BLOCK_SIZE) {
            ctx->block[i++] = 0x00;
        }
        sha512_transform(ctx, ctx->block);
        memset(ctx->block, 0, SHA512_BLOCK_SIZE - 16);
    }

    /* Append the total length of the input data */
    ctx->total_len += ctx->len;
    ctx->block[SHA512_BLOCK_SIZE - 1] = (uint8_t)(ctx->total_len);
    ctx->block[SHA512_BLOCK_SIZE - 2] = (uint8_t)(ctx->total_len >> 8);
    ctx->block[SHA512_BLOCK_SIZE - 3] = (uint8_t)(ctx->total_len >> 16);
    ctx->block[SHA512_BLOCK_SIZE - 4] = (uint8_t)(ctx->total_len >> 24);
    ctx->block[SHA512_BLOCK_SIZE - 5] = (uint8_t)(ctx->total_len >> 32);
    ctx->block[SHA512_BLOCK_SIZE - 6] = (uint8_t)(ctx->total_len >> 40);
    ctx->block[SHA512_BLOCK_SIZE - 7] = (uint8_t)(ctx->total_len >> 48);
    ctx->block[SHA512_BLOCK_SIZE - 8] = (uint8_t)(ctx->total_len >> 56);
    sha512_transform(ctx, ctx->block);

    /* Convert the hash to output bytes */
    for (i = 0; i < 8; ++i) {
        hash[i * 8 + 0] = (uint8_t)(ctx->h[i] >> 56);
        hash[i * 8 + 1] = (uint8_t)(ctx->h[i] >> 48);
        hash[i * 8 + 2] = (uint8_t)(ctx->h[i] >> 40);
        hash[i * 8 + 3] = (uint8_t)(ctx->h[i] >> 32);
        hash[i * 8 + 4] = (uint8_t)(ctx->h[i] >> 24);
        hash[i * 8 + 5] = (uint8_t)(ctx->h[i] >> 16);
        hash[i * 8 + 6] = (uint8_t)(ctx->h[i] >>  8);
        hash[i * 8 + 7] = (uint8_t)(ctx->h[i] >>  0);
    }
}

int main(void)
{
    sha512_ctx ctx;
    uint8_t hash[64];
    char message[] = "Hello, world!";

    sha512_init(&ctx);
    sha512_update(&ctx, (uint8_t *)message, strlen(message));
    sha512_finalize(&ctx, hash);

    for (int i = 0; i < 64; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}