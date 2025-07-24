//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE  64
#define DIGEST_SIZE 20

typedef struct
{
    unsigned char data[BLOCK_SIZE];
    unsigned int datalen;
    unsigned long long bitlen;
    unsigned int state[5];
} SHA1_CTX;

void sha1_transform(SHA1_CTX *ctx, unsigned char *data);
void sha1_init(SHA1_CTX *ctx);
void sha1_update(SHA1_CTX *ctx, unsigned char *data, unsigned int len);
void sha1_final(SHA1_CTX *ctx, unsigned char *digest);

unsigned char *sha1(unsigned char *data, size_t len)
{
    SHA1_CTX ctx;
    unsigned char *digest = malloc(DIGEST_SIZE);

    sha1_init(&ctx);
    sha1_update(&ctx, data, len);
    sha1_final(&ctx, digest);

    return digest;
}

void sha1_transform(SHA1_CTX *ctx, unsigned char *data)
{
    unsigned int a, b, c, d, e, i, j, t, m[80];

    for (i = 0, j = 0; i < 16; ++i, j += 4)
        m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
  
    for (; i < 80; ++i)
        m[i] = (m[i - 3] ^ m[i - 8] ^ m[i - 14] ^ m[i - 16]);

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];

    for (i = 0; i < 80; ++i)
    {
        if (i < 20)
            t = ((b & c) | ((~b) & d)) + 0x5A827999;
        else if (i < 40)
            t = (b ^ c ^ d) + 0x6ED9EBA1;
        else if (i < 60)
            t = ((b & c) | (b & d) | (c & d)) + 0x8F1BBCDC;
        else
            t = (b ^ c ^ d) + 0xCA62C1D6;

        t += e + m[i];
        e = d;
        d = c;
        c = (b << 30) | (b >> 2);
        b = a;
        a = t;
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
}

void sha1_init(SHA1_CTX *ctx)
{
    ctx->datalen = 0;
    ctx->bitlen = 0;
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xC3D2E1F0;
}

void sha1_update(SHA1_CTX *ctx, unsigned char *data, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; ++i)
    {
        ctx->data[ctx->datalen] = data[i];
        ctx->datalen++;

        if (ctx->datalen == BLOCK_SIZE)
        {
            sha1_transform(ctx, ctx->data);
            ctx->bitlen += 512;
            ctx->datalen = 0;
        }
    }
}

void sha1_final(SHA1_CTX *ctx, unsigned char *digest)
{
    unsigned int i;

    i = ctx->datalen;

    if (ctx->datalen < 56)
    {
        ctx->data[i++] = 0x80;

        while (i < 56)
            ctx->data[i++] = 0x00;
    }
    else
    {
        ctx->data[i++] = 0x80;

        while (i < 64)
            ctx->data[i++] = 0x00;

        sha1_transform(ctx, ctx->data);
        memset(ctx->data, 0, 56);
    }

    ctx->bitlen += ctx->datalen * 8;
    ctx->data[63] = ctx->bitlen;
    ctx->data[62] = ctx->bitlen >> 8;
    ctx->data[61] = ctx->bitlen >> 16;
    ctx->data[60] = ctx->bitlen >> 24;
    ctx->data[59] = ctx->bitlen >> 32;
    ctx->data[58] = ctx->bitlen >> 40;
    ctx->data[57] = ctx->bitlen >> 48;
    ctx->data[56] = ctx->bitlen >> 56;
    sha1_transform(ctx, ctx->data);

    for (i = 0; i < 4; ++i)
        digest[i]      = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
    for (i = 0; i < 4; ++i)
        digest[i + 4]  = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
    for (i = 0; i < 4; ++i)
        digest[i + 8]  = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
    for (i = 0; i < 4; ++i)
        digest[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
    for (i = 0; i < 4; ++i)
        digest[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
}

int main()
{
    unsigned char data[] = "Mind-bending SHA1 example program";
    unsigned char *digest = sha1(data, strlen(data));

    printf("SHA1 digest: ");

    for (int i = 0; i < DIGEST_SIZE; ++i)
        printf("%02x", digest[i]);

    free(digest);

  return 0;
}