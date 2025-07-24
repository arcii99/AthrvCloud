//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,n) ((x) << (n)) | ((x) >> (32 - (n)))
#define ROTR(x,n) ((x) >> (n)) | ((x) << (32 - (n)))

uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (~x & z);
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & ~z);
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | ~z);
}

typedef struct {
    uint32_t state[4];
    uint32_t count[2];
    uint8_t buffer[64];
} md5_ctx_t;

void md5_init(md5_ctx_t* ctx) {
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;

    ctx->count[0] = 0;
    ctx->count[1] = 0;

    memset(ctx->buffer, 0, 64);
}

void md5_transform(md5_ctx_t* ctx, const uint8_t* data) {
    uint32_t a = ctx->state[0];
    uint32_t b = ctx->state[1];
    uint32_t c = ctx->state[2];
    uint32_t d = ctx->state[3];
    uint32_t x[16];

    for (int i = 0; i < 16; ++i) {
        x[i] = (data[i * 4]) | (data[i * 4 + 1] << 8) | (data[i * 4 + 2] << 16) | (data[i * 4 + 3] << 24);
    }

    // round 1
    for (int i = 0; i < 16; ++i) {
        uint32_t f = F(b, c, d);
        uint32_t g = i;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + ROTL((a + f + x[g]), 7);
        a = temp;
    }

    // round 2
    for (int i = 0; i < 16; ++i) {
        uint32_t f = G(b, c, d);
        uint32_t g = (5 * i + 1) % 16;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + ROTL((a + f + x[g] + 0x5a827999), 12);
        a = temp;
    }

    // round 3
    for (int i = 0; i < 16; ++i) {
        uint32_t f = H(b, c, d);
        uint32_t g = (3 * i + 5) % 16;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + ROTL((a + f + x[g] + 0x6ed9eba1), 17);
        a = temp;
    }

    // round 4
    for (int i = 0; i < 16; ++i) {
        uint32_t f = I(b, c, d);
        uint32_t g = (7 * i) % 16;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + ROTL((a + f + x[g] + 0x8f1bbcdc), 22);
        a = temp;
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
}

void md5_update(md5_ctx_t* ctx, const uint8_t* data, uint32_t length) {
    uint32_t index = ctx->count[0] / 8 % 64;

    if ((ctx->count[0] += length << 3) < (length << 3)) {
        ++ctx->count[1];
    }

    ctx->count[1] += length >> 29;

    uint32_t partlen = 64 - index;

    if (length >= partlen) {
        memcpy(&ctx->buffer[index], data, partlen);
        md5_transform(ctx, ctx->buffer);

        for (int i = partlen; i + 63 < length; i += 64) {
            md5_transform(ctx, &data[i]);
        }

        index = 0;
    }

    memcpy(&ctx->buffer[index], &data[length - partlen], partlen);
}

void md5_final(md5_ctx_t* ctx, uint8_t* digest) {
    uint8_t padding[64] = { 0x80, 0 };

    uint32_t index = ctx->count[0] / 8 % 64;
    uint32_t value = 0;

    if (index < 56) {
        md5_update(ctx, padding, 56 - index);
    }
    else {
        md5_update(ctx, padding, 64 + 56 - index);
    }

    value = ctx->count[0];
    memcpy(&ctx->buffer[56], &value, 4);
    value = ctx->count[1];
    memcpy(&ctx->buffer[60], &value, 4);

    md5_transform(ctx, ctx->buffer);

    for (int i = 0; i < 4; ++i) {
        digest[i] = (ctx->state[0] >> (i * 8)) & 0xff;
        digest[i + 4] = (ctx->state[1] >> (i * 8)) & 0xff;
        digest[i + 8] = (ctx->state[2] >> (i * 8)) & 0xff;
        digest[i + 12] = (ctx->state[3] >> (i * 8)) & 0xff;
    }
}

int main() {
    md5_ctx_t ctx;
    uint8_t digest[16];
    char* str = "MD5 Example Program";

    md5_init(&ctx);
    md5_update(&ctx, (uint8_t*)str, strlen(str));
    md5_final(&ctx, digest);

    printf("MD5 hash of '%s':\n", str);
    for (int i = 0; i < 16; ++i) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}