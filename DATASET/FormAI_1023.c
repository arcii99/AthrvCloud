//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROTL(x, y) ((x << y) | (x >> (32 - y)))

typedef struct {
    unsigned int H[8];
    unsigned int K[64];
    unsigned char buffer[64];
    unsigned int blk_idx;
} SHA256_CTX;

void sha256_transform(SHA256_CTX *ctx) {
    unsigned int W[64], a, b, c, d, e, f, g, h, i, j, t1, t2;

    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        W[i] = (ctx->buffer[j] << 24) | (ctx->buffer[j + 1] << 16)
               | (ctx->buffer[j + 2] << 8) | (ctx->buffer[j + 3]);
    }
    for (; i < 64; ++i) {
        W[i] = W[i - 16] + W[i - 7] + (ROTL(W[i - 15], 7) ^ ROTL(W[i - 15], 18) ^ (W[i - 15] >> 3))
               + (ROTL(W[i - 2], 17) ^ ROTL(W[i - 2], 19) ^ (W[i - 2] >> 10));
    }

    a = ctx->H[0];
    b = ctx->H[1];
    c = ctx->H[2];
    d = ctx->H[3];
    e = ctx->H[4];
    f = ctx->H[5];
    g = ctx->H[6];
    h = ctx->H[7];

    for (i = 0; i < 64; ++i) {
        t1 = h + (ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25)) + ((e & f) ^ (~e & g)) + ctx->K[i] + W[i];
        t2 = (ROTL(a, 2) ^ ROTL(a, 13) ^ ROTL(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    ctx->H[0] += a;
    ctx->H[1] += b;
    ctx->H[2] += c;
    ctx->H[3] += d;
    ctx->H[4] += e;
    ctx->H[5] += f;
    ctx->H[6] += g;
    ctx->H[7] += h;
}

void sha256_update(SHA256_CTX *ctx, const unsigned char *data, unsigned int len) {
    unsigned int i;

    for (i = 0; i < len; i++) {
        ctx->buffer[ctx->blk_idx++] = data[i];

        if (ctx->blk_idx == 64) {
            sha256_transform(ctx);
            ctx->blk_idx = 0;
        }
    }
}

void sha256_final(SHA256_CTX *ctx, unsigned char *hash) {
    unsigned int i;

    ctx->buffer[ctx->blk_idx++] = 0x80;
    while (ctx->blk_idx != 56) {
        if (ctx->blk_idx == 64) {
            sha256_transform(ctx);
            ctx->blk_idx = 0;
        }
        ctx->buffer[ctx->blk_idx++] = 0x00;
    }
    unsigned long long int bit_len = ctx->blk_idx << 3;
    ctx->buffer[56] = (bit_len >> 56) & 0xFF;
    ctx->buffer[57] = (bit_len >> 48) & 0xFF;
    ctx->buffer[58] = (bit_len >> 40) & 0xFF;
    ctx->buffer[59] = (bit_len >> 32) & 0xFF;
    ctx->buffer[60] = (bit_len >> 24) & 0xFF;
    ctx->buffer[61] = (bit_len >> 16) & 0xFF;
    ctx->buffer[62] = (bit_len >> 8) & 0xFF;
    ctx->buffer[63] = bit_len & 0xFF;
    sha256_transform(ctx);

    for (i = 0; i < 8; ++i) {
        hash[i * 4] = (ctx->H[i] >> 24) & 0xFF;
        hash[i * 4 + 1] = (ctx->H[i] >> 16) & 0xFF;
        hash[i * 4 + 2] = (ctx->H[i] >> 8) & 0xFF;
        hash[i * 4 + 3] = ctx->H[i] & 0xFF;
    }
}

void sha256(unsigned char *data, unsigned int len, unsigned char *hash) {
    SHA256_CTX ctx;
    ctx.H[0] = 0x6a09e667;
    ctx.H[1] = 0xbb67ae85;
    ctx.H[2] = 0x3c6ef372;
    ctx.H[3] = 0xa54ff53a;
    ctx.H[4] = 0x510e527f;
    ctx.H[5] = 0x9b05688c;
    ctx.H[6] = 0x1f83d9ab;
    ctx.H[7] = 0x5be0cd19;

    ctx.K[0] = 0x428a2f98;
    ctx.K[1] = 0x71374491;
    ctx.K[2] = 0xb5c0fbcf;
    ctx.K[3] = 0xe9b5dba5;
    ctx.K[4] = 0x3956c25b;
    ctx.K[5] = 0x59f111f1;
    ctx.K[6] = 0x923f82a4;
    ctx.K[7] = 0xab1c5ed5;
    ctx.K[8] = 0xd807aa98;
    ctx.K[9] = 0x12835b01;
    ctx.K[10] = 0x243185be;
    ctx.K[11] = 0x550c7dc3;
    ctx.K[12] = 0x72be5d74;
    ctx.K[13] = 0x80deb1fe;
    ctx.K[14] = 0x9bdc06a7;
    ctx.K[15] = 0xc19bf174;
    ctx.K[16] = 0xe49b69c1;
    ctx.K[17] = 0xefbe4786;
    ctx.K[18] = 0x0fc19dc6;
    ctx.K[19] = 0x240ca1cc;
    ctx.K[20] = 0x2de92c6f;
    ctx.K[21] = 0x4a7484aa;
    ctx.K[22] = 0x5cb0a9dc;
    ctx.K[23] = 0x76f988da;
    ctx.K[24] = 0x983e5152;
    ctx.K[25] = 0xa831c66d;
    ctx.K[26] = 0xb00327c8;
    ctx.K[27] = 0xbf597fc7;
    ctx.K[28] = 0xc6e00bf3;
    ctx.K[29] = 0xd5a79147;
    ctx.K[30] = 0x06ca6351;
    ctx.K[31] = 0x14292967;
    ctx.K[32] = 0x27b70a85;
    ctx.K[33] = 0x2e1b2138;
    ctx.K[34] = 0x4d2c6dfc;
    ctx.K[35] = 0x53380d13;
    ctx.K[36] = 0x650a7354;
    ctx.K[37] = 0x766a0abb;
    ctx.K[38] = 0x81c2c92e;
    ctx.K[39] = 0x92722c85;
    ctx.K[40] = 0xa2bfe8a1;
    ctx.K[41] = 0xa81a664b;
    ctx.K[42] = 0xc24b8b70;
    ctx.K[43] = 0xc76c51a3;
    ctx.K[44] = 0xd192e819;
    ctx.K[45] = 0xd6990624;
    ctx.K[46] = 0xf40e3585;
    ctx.K[47] = 0x106aa070;
    ctx.K[48] = 0x19a4c116;
    ctx.K[49] = 0x1e376c08;
    ctx.K[50] = 0x2748774c;
    ctx.K[51] = 0x34b0bcb5;
    ctx.K[52] = 0x391c0cb3;
    ctx.K[53] = 0x4ed8aa4a;
    ctx.K[54] = 0x5b9cca4f;
    ctx.K[55] = 0x682e6ff3;
    ctx.K[56] = 0x748f82ee;
    ctx.K[57] = 0x78a5636f;
    ctx.K[58] = 0x84c87814;
    ctx.K[59] = 0x8cc70208;
    ctx.K[60] = 0x90befffa;
    ctx.K[61] = 0xa4506ceb;
    ctx.K[62] = 0xbef9a3f7;
    ctx.K[63] = 0xc67178f2;

    ctx.blk_idx = 0;
    memset(ctx.buffer, 0, 64);

    sha256_update(&ctx, data, len);
    sha256_final(&ctx, hash);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;

    unsigned char hash[32];
    sha256((unsigned char *) str, strlen(str), hash);

    printf("SHA256 hash of '%s' is: ", str);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}