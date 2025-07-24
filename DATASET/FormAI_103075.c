//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define ROUND1(a,b,c,d,x,s) { a += ((b & c) | ((~b) & d)) + x; a = ROTATE_LEFT(a,s); a += b; }
#define ROUND2(a,b,c,d,x,s) { a += ((b & d) | (c & (~d))) + x + 0x5A827999; a = ROTATE_LEFT(a,s); a += b; }
#define ROUND3(a,b,c,d,x,s) { a += (b ^ c ^ d) + x + 0x6ED9EBA1; a = ROTATE_LEFT(a,s); a += b; }
#define ROUND4(a,b,c,d,x,s) { a += ((~b) | c) ^ d + x + 0x8F1BBCDC; a = ROTATE_LEFT(a,s); a += b; }
#define ROUND5(a,b,c,d,x,s) { a += (c ^ (~d) ^ b) + x + 0xCA62C1D6; a = ROTATE_LEFT(a,s); a += b; }

typedef struct {
    uint8_t data[64];
    uint32_t datalen;
    uint32_t bitlen[2];
    uint32_t state[5];
} SHA1_CTX;

void sha1_transform(SHA1_CTX *ctx, const uint8_t data[]) {
    uint32_t a, b, c, d, e, w[80], i;

    for (i = 0; i < 16; i++) {
        w[i] = (data[i*4] << 24) | (data[i*4 + 1] << 16) | (data[i*4 + 2] << 8) | (data[i*4 + 3]);
    }
    for (i = 16; i < 80; i++) {
        w[i] = ROTATE_LEFT((w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]), 1);
    }
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];

    for (i = 0; i < 20; i++) {
        ROUND1(a, b, c, d, w[i], 5);
    }
    for (i = 20; i < 40; i++) {
        ROUND2(a, b, c, d, w[i], 9);
    }
    for (i = 40; i < 60; i++) {
        ROUND3(a, b, c, d, w[i], 13);
    }
    for (i = 60; i < 80; i++) {
        ROUND4(a, b, c, d, w[i], 21);
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
}

void sha1_init(SHA1_CTX *ctx) {
    ctx->datalen = 0;
    ctx->bitlen[0] = 0;
    ctx->bitlen[1] = 0;
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xC3D2E1F0;
}

void sha1_update(SHA1_CTX *ctx, const uint8_t data[], size_t len) {
    uint32_t i;

    for (i = 0; i < len; i++) {
        ctx->data[ctx->datalen] = data[i];
        ctx->datalen++;
        if (ctx->datalen == 64) {
            sha1_transform(ctx, ctx->data);
            ctx->bitlen[0] += 512;
            ctx->datalen = 0;
        }
    }
}

void sha1_final(SHA1_CTX *ctx, uint8_t hash[]) {
    uint32_t i;

    i = ctx->datalen;

    if (ctx->datalen < 56) {
        ctx->data[i++] = 0x80;
        while (i < 56) {
            ctx->data[i++] = 0x00;
        }
    } else {
        ctx->data[i++] = 0x80;
        while (i < 64) {
            ctx->data[i++] = 0x00;
        }
        sha1_transform(ctx, ctx->data);
        memset(ctx->data, 0, 56);
    }

    ctx->bitlen[0] += ctx->datalen * 8;
    ctx->bitlen[1] += ctx->bitlen[0] < (ctx->datalen * 8);
    ctx->bitlen[0] = ctx->bitlen[0] & 0xFFFFFFFF;
    ctx->bitlen[1] = ctx->bitlen[1] & 0xFFFFFFFF;

    ctx->data[63] = ctx->bitlen[0] & 0xFF;
    ctx->data[62] = (ctx->bitlen[0] >> 8) & 0xFF;
    ctx->data[61] = (ctx->bitlen[0] >> 16) & 0xFF;
    ctx->data[60] = (ctx->bitlen[0] >> 24) & 0xFF;
    ctx->data[59] = ctx->bitlen[1] & 0xFF;
    ctx->data[58] = (ctx->bitlen[1] >> 8) & 0xFF;
    ctx->data[57] = (ctx->bitlen[1] >> 16) & 0xFF;
    ctx->data[56] = (ctx->bitlen[1] >> 24) & 0xFF;

    sha1_transform(ctx, ctx->data);

    for (i = 0; i < 20; i++) {
        hash[i] = (ctx->state[i>>2] >> ((3 - (i & 3)) * 8)) & 0xFF;
    }
}

int main() {
    char input[100];
    uint8_t hash[20];
    SHA1_CTX ctx;

    printf("Enter string: \n");
    fgets(input, 100, stdin);

    sha1_init(&ctx);
    sha1_update(&ctx, input, strlen(input) - 1);
    sha1_final(&ctx, hash);

    printf("Hash result: ");
    for (int i = 0; i < 20; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}