//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned int uint;

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))
#define ROTR(x, y) (((x) >> (y)) | ((x) << (32 - (y))))

#define U8TO32_LE(p)                         \
    (((uint)((p)[0]) << 0) | ((uint)((p)[1]) << 8) |  \
     ((uint)((p)[2]) << 16) | ((uint)((p)[3]) << 24))

#define U32TO8_LE(p, v)                \
    (p)[0] = (byte)((v) >> 0);   \
    (p)[1] = (byte)((v) >> 8);   \
    (p)[2] = (byte)((v) >> 16);  \
    (p)[3] = (byte)((v) >> 24)

typedef struct {
    uint h[8], s[4], t[2];
    byte buf[64];
    int buflen, nullt;
} sha256;

const uint K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
};

const uint H0[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

void sha256_transform(sha256 *ctx, byte *buf) {
    uint a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];
    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        m[i] = U8TO32_LE(buf + j);
    }
    for (; i < 64; ++i) {
        m[i] = m[i - 16] + m[i - 7] + (ROTR(m[i - 15], 7) ^ ROTR(m[i - 15], 18) ^ (m[i - 15] >> 3)) +
               (ROTR(m[i - 2], 17) ^ ROTR(m[i - 2], 19) ^ (m[i - 2] >> 10));
    }
    a = ctx->h[0], b = ctx->h[1], c = ctx->h[2], d = ctx->h[3];
    e = ctx->h[4], f = ctx->h[5], g = ctx->h[6], h = ctx->h[7];
    for (i = 0; i < 64; ++i) {
        t1 = h + (ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25)) + ((e & f) ^ (~e & g)) + K[i] + m[i];
        t2 = (ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
        h = g, g = f, f = e, e = d + t1, d = c, c = b, b = a, a = t1 + t2;
    }
    ctx->h[0] += a, ctx->h[1] += b, ctx->h[2] += c, ctx->h[3] += d;
    ctx->h[4] += e, ctx->h[5] += f, ctx->h[6] += g, ctx->h[7] += h;
}

void sha256_init(sha256 *ctx) {
    int i;
    for (i = 0; i < 8; ++i) {
        ctx->h[i] = H0[i];
    }
    for (i = 0; i < 4; ++i) {
        ctx->s[i] = 0;
    }
    for (i = 0; i < 2; ++i) {
        ctx->t[i] = 0;
    }
    ctx->buflen = 0;
    ctx->nullt = 1;
}

void sha256_update(sha256 *ctx, byte *buf, uint len) {
    if (ctx->buflen + len > 64) {
        memcpy(ctx->buf + ctx->buflen, buf, 64 - ctx->buflen);
        ctx->t[0] += 512, sha256_transform(ctx, ctx->buf);
        ctx->buflen = 0;
    }
    if (ctx->buflen == 0 && len == 64) {
        ctx->t[0] += 512, sha256_transform(ctx, buf);
    } else {
        memcpy(ctx->buf + ctx->buflen, buf, len);
        ctx->buflen += len;
    }
}

void sha256_final(sha256 *ctx, byte *hash) {
    uint i = ctx->buflen;
    if (ctx->nullt) {
        ctx->t[0] += i << 3;
        ctx->buf[i++] = 0x80;
        while (i < 64) {
            ctx->buf[i++] = 0;
        }
        sha256_transform(ctx, ctx->buf);
    } else {
        ctx->t[0] += i << 3;
        sha256_transform(ctx, ctx->buf);
    }
    ctx->t[1] += ctx->t[0] >> 32;
    U32TO8_LE(hash + 0, ctx->h[0]);
    U32TO8_LE(hash + 4, ctx->h[1]);
    U32TO8_LE(hash + 8, ctx->h[2]);
    U32TO8_LE(hash + 12, ctx->h[3]);
    U32TO8_LE(hash + 16, ctx->h[4]);
    U32TO8_LE(hash + 20, ctx->h[5]);
    U32TO8_LE(hash + 24, ctx->h[6]);
    U32TO8_LE(hash + 28, ctx->h[7]);
}

int main(int argc, char **argv) {
    char *data = "This is a test string";
    byte hash[32];
    sha256 ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, (byte *)data, strlen(data));
    sha256_final(&ctx, hash);
    printf("Hash for '%s': ", data);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}